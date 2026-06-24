#include "CliCommands.h"

#include <ostream>

#ifndef DIRECTIONAL_VERSION
#define DIRECTIONAL_VERSION "0.0.0"
#endif

extern "C" const char *directional_build_info();

namespace directional::cli {

void print_version(std::ostream &stream) {
  stream << "directional-cli " << DIRECTIONAL_VERSION << '\n';
}

int run_info(std::ostream &stream) {
  print_version(stream);
  stream << "native library: " << directional_build_info() << '\n';
  return 0;
}

} // namespace directional::cli
