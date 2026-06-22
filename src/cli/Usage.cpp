#include "CliCommands.h"

#include <ostream>

namespace directional::cli {

void print_usage(std::ostream &stream) {
  stream
      << "Directional native command line interface\n\n"
      << "Usage:\n"
      << "  directional info\n"
      << "  directional cross-field <input.obj|input.off> <output.rawfield> "
         "[options]\n"
      << "  directional --version\n"
      << "  directional --help\n\n"
      << "Commands:\n"
      << "  info         Show native library build information.\n"
      << "  cross-field  Extract a smooth face-based 4-RoSy field.\n\n"
      << "cross-field options:\n"
      << "  --singularities <path>  Write field singularities to a .sings file.\n"
      << "  --no-normalize          Preserve computed direction magnitudes.\n\n";
}

} // namespace directional::cli
