#include "CliBackend.h"
#include "CliCommands.h"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

namespace directional::cli {
namespace {

int dispatch(const int argc, char **argv) {
  if (argc <= 1) {
    print_usage(std::cout);
    return 0;
  }

  const std::string command = argv[1];
  if (command == "--help" || command == "-h" || command == "help") {
    print_usage(std::cout);
    return 0;
  }
  if (command == "--version" || command == "-V") {
    print_version(std::cout);
    return 0;
  }
  if (command == "info") {
    return run_info(std::cout);
  }
  if (command == "cross-field") {
    return run_cross_field(argc, argv);
  }
  if (command == "convert-field") {
    return run_convert_field(argc, argv);
  }
  if (command == "remesh") {
    return run_remesh(argc, argv);
  }

  std::cerr << "directional: unknown command: " << command << '\n';
  std::cerr << "Run `directional --help` for usage.\n";
  return 2;
}

} // namespace

int run_cli(const int argc, char **argv) {
  try {
    return dispatch(argc, argv);
  } catch (const std::exception &error) {
    std::cerr << "directional: error: " << error.what() << '\n';
    return 1;
  }
}

int run_cli(const std::vector<std::string> &arguments) {
  std::vector<std::string> storage;
  storage.reserve(arguments.size() + 1);
  storage.emplace_back("directional");
  storage.insert(storage.end(), arguments.begin(), arguments.end());

  std::vector<char *> argv;
  argv.reserve(storage.size());
  for (std::string &argument : storage) {
    argv.push_back(argument.data());
  }
  return run_cli(static_cast<int>(argv.size()), argv.data());
}

} // namespace directional::cli
