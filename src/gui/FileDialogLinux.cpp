#include "FileDialog.h"

#if defined(DIRECTIONAL_GUI_HAS_GIO)
#include <gio/gio.h>
#endif

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <random>
#include <string>
#include <system_error>
#include <vector>

namespace directional::gui {

#if defined(DIRECTIONAL_GUI_HAS_GIO)
namespace {

struct PortalResponse {
  GMainLoop *loop = nullptr;
  FileDialogResult result;
};

std::string error_message(const char *prefix, const GError *error) {
  std::string message(prefix);
  if (error != nullptr && error->message != nullptr) {
    message += ": ";
    message += error->message;
  }
  return message;
}

std::filesystem::path initial_directory(
    const std::filesystem::path &initialPath) {
  if (initialPath.empty()) {
    return {};
  }

  std::error_code error;
  if (std::filesystem::is_directory(initialPath, error) && !error) {
    return initialPath;
  }
  return initialPath.parent_path();
}

std::string make_handle_token() {
  std::random_device randomDevice;
  std::mt19937_64 generator(randomDevice());
  std::uniform_int_distribution<unsigned long long> distribution;
  return "directional_" + std::to_string(distribution(generator));
}

std::string request_path_for(GDBusConnection *connection,
                             const std::string &token) {
  const gchar *uniqueName = g_dbus_connection_get_unique_name(connection);
  if (uniqueName == nullptr) {
    return {};
  }
  std::string sender(uniqueName);
  if (!sender.empty() && sender.front() == ':') {
    sender.erase(sender.begin());
  }
  std::replace(sender.begin(), sender.end(), '.', '_');
  return "/org/freedesktop/portal/desktop/request/" + sender + "/" + token;
}

std::string case_insensitive_glob(const std::string &pattern) {
  std::string converted;
  converted.reserve(pattern.size() * 2);
  for (const unsigned char character : pattern) {
    if (std::isalpha(character) != 0) {
      converted.push_back('[');
      converted.push_back(static_cast<char>(std::tolower(character)));
      converted.push_back(static_cast<char>(std::toupper(character)));
      converted.push_back(']');
    } else {
      converted.push_back(static_cast<char>(character));
    }
  }
  return converted;
}

GVariant *build_filters(const std::vector<FileDialogFilter> &filters) {
  GVariantBuilder filterList;
  g_variant_builder_init(&filterList, G_VARIANT_TYPE("a(sa(us))"));

  for (const FileDialogFilter &filter : filters) {
    GVariantBuilder patterns;
    g_variant_builder_init(&patterns, G_VARIANT_TYPE("a(us)"));
    for (const std::string &pattern : filter.patterns) {
      const std::string converted = case_insensitive_glob(pattern);
      g_variant_builder_add(&patterns, "(us)", 0U, converted.c_str());
    }
    g_variant_builder_add(&filterList, "(s@a(us))", filter.name.c_str(),
                          g_variant_builder_end(&patterns));
  }

  return g_variant_builder_end(&filterList);
}

void portal_response_callback(GDBusConnection *, const gchar *, const gchar *,
                              const gchar *, const gchar *,
                              GVariant *parameters, gpointer userData) {
  auto *response = static_cast<PortalResponse *>(userData);

  guint32 responseCode = 2;
  GVariant *results = nullptr;
  g_variant_get(parameters, "(u@a{sv})", &responseCode, &results);

  if (responseCode == 1) {
    response->result = {FileDialogStatus::Cancelled, {}, {}};
  } else if (responseCode != 0) {
    response->result = {FileDialogStatus::Failed, {},
                        "The XDG file chooser portal ended without a selection."};
  } else {
    GVariant *uris =
        g_variant_lookup_value(results, "uris", G_VARIANT_TYPE("as"));
    if (uris == nullptr || g_variant_n_children(uris) == 0) {
      response->result = {FileDialogStatus::Failed, {},
                          "The XDG file chooser portal returned no file URI."};
    } else {
      GVariant *uriValue = g_variant_get_child_value(uris, 0);
      const gchar *uri = g_variant_get_string(uriValue, nullptr);
      GError *conversionError = nullptr;
      gchar *filename = g_filename_from_uri(uri, nullptr, &conversionError);
      if (filename == nullptr) {
        response->result = {
            FileDialogStatus::Failed, {},
            error_message("Unable to convert the portal file URI",
                          conversionError)};
      } else {
        response->result = {FileDialogStatus::Selected,
                            std::filesystem::path(filename), {}};
        g_free(filename);
      }
      if (conversionError != nullptr) {
        g_error_free(conversionError);
      }
      g_variant_unref(uriValue);
    }
    if (uris != nullptr) {
      g_variant_unref(uris);
    }
  }

  g_variant_unref(results);
  g_main_loop_quit(response->loop);
}

} // namespace
#endif

FileDialogResult open_native_file_dialog(const FileDialogOptions &options) {
#if !defined(DIRECTIONAL_GUI_HAS_GIO)
  (void)options;
  return {FileDialogStatus::Unavailable, {},
          "The Linux GUI was built without GIO/GDBus support."};
#else
  GError *error = nullptr;
  GDBusConnection *connection =
      g_bus_get_sync(G_BUS_TYPE_SESSION, nullptr, &error);
  if (connection == nullptr) {
    const std::string message =
        error_message("Unable to connect to the session D-Bus", error);
    if (error != nullptr) {
      g_error_free(error);
    }
    return {FileDialogStatus::Unavailable, {}, message};
  }

  const std::string token = make_handle_token();
  std::string requestPath = request_path_for(connection, token);
  if (requestPath.empty()) {
    g_object_unref(connection);
    return {FileDialogStatus::Unavailable, {},
            "The session D-Bus connection has no unique name."};
  }

  PortalResponse response;
  response.loop = g_main_loop_new(nullptr, FALSE);
  response.result = {FileDialogStatus::Failed, {},
                     "The XDG file chooser portal did not respond."};

  guint subscription = g_dbus_connection_signal_subscribe(
      connection, "org.freedesktop.portal.Desktop",
      "org.freedesktop.portal.Request", "Response", requestPath.c_str(),
      nullptr, G_DBUS_SIGNAL_FLAGS_NONE, portal_response_callback, &response,
      nullptr);

  GVariantBuilder optionBuilder;
  g_variant_builder_init(&optionBuilder, G_VARIANT_TYPE_VARDICT);
  g_variant_builder_add(&optionBuilder, "{sv}", "handle_token",
                        g_variant_new_string(token.c_str()));
  g_variant_builder_add(&optionBuilder, "{sv}", "modal",
                        g_variant_new_boolean(TRUE));
  if (!options.filters.empty()) {
    g_variant_builder_add(&optionBuilder, "{sv}", "filters",
                          build_filters(options.filters));
  }

  const std::filesystem::path directory =
      initial_directory(options.initialPath);
  if (!directory.empty()) {
    std::string folder = directory.native();
    folder.push_back('\0');
    GVariant *folderBytes = g_variant_new_fixed_array(
        G_VARIANT_TYPE_BYTE, folder.data(), folder.size(), sizeof(guint8));
    g_variant_builder_add(&optionBuilder, "{sv}", "current_folder",
                          folderBytes);
  }

  GVariant *reply = g_dbus_connection_call_sync(
      connection, "org.freedesktop.portal.Desktop",
      "/org/freedesktop/portal/desktop",
      "org.freedesktop.portal.FileChooser", "OpenFile",
      g_variant_new("(ss@a{sv})", "", options.title.c_str(),
                    g_variant_builder_end(&optionBuilder)),
      G_VARIANT_TYPE("(o)"), G_DBUS_CALL_FLAGS_NONE, -1, nullptr, &error);

  if (reply == nullptr) {
    const std::string message =
        error_message("Unable to open the XDG file chooser portal", error);
    if (error != nullptr) {
      g_error_free(error);
    }
    g_dbus_connection_signal_unsubscribe(connection, subscription);
    g_main_loop_unref(response.loop);
    g_object_unref(connection);
    return {FileDialogStatus::Unavailable, {}, message};
  }

  const gchar *returnedPath = nullptr;
  g_variant_get(reply, "(&o)", &returnedPath);
  if (returnedPath != nullptr && requestPath != returnedPath) {
    g_dbus_connection_signal_unsubscribe(connection, subscription);
    requestPath = returnedPath;
    subscription = g_dbus_connection_signal_subscribe(
        connection, "org.freedesktop.portal.Desktop",
        "org.freedesktop.portal.Request", "Response", requestPath.c_str(),
        nullptr, G_DBUS_SIGNAL_FLAGS_NONE, portal_response_callback, &response,
        nullptr);
  }
  g_variant_unref(reply);

  g_main_loop_run(response.loop);

  g_dbus_connection_signal_unsubscribe(connection, subscription);
  g_main_loop_unref(response.loop);
  g_object_unref(connection);
  return response.result;
#endif
}

} // namespace directional::gui
