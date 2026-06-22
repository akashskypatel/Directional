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
      << "  directional remesh <input.obj|input.off> <output.off> [options]\n"
      << "  directional --version\n"
      << "  directional --help\n\n"
      << "Commands:\n"
      << "  info         Show native library build information.\n"
      << "  cross-field  Extract a smooth face-based 4-RoSy field.\n"
      << "  remesh       Remesh a triangle mesh, extracting a cross field when one "
         "is not supplied.\n\n"
      << "cross-field options:\n"
      << "  --no-normalize-directions  Preserve computed direction magnitudes.\n"
      << "  --no-normalize             Backward-compatible alias.\n"
      << "  --no-matching              Skip edge matching and singularity analysis.\n"
      << "  --singularities <path>     Write singularities to a .sings file.\n"
      << "  --diagnostics-prefix <p>   Write primary/secondary directions, matching, "
         "effort, and singularity arrays as sidecars.\n"
      << "  --verbose                  Print processing details.\n\n"
      << "remesh options:\n"
      << "  --raw-field <path>              Use a degree-4 .rawfield file.\n"
      << "  --primary-directions <path>     Use a #F x 3 DMAT direction matrix.\n"
      << "  --secondary-directions <path>   Use a second #F x 3 DMAT matrix.\n"
      << "  --length-ratio <value>           Target edge-length ratio (default 0.02).\n"
      << "  --no-integral-seamless           Disable integral seamless constraints.\n"
      << "  --round-seams                    Round seam values during integration.\n"
      << "  --feature-align                  Request feature alignment; currently "
         "unsupported by the headless pipeline.\n"
      << "  --no-normalize-directions        Preserve supplied direction magnitudes.\n"
      << "  --diagnostics-prefix <p>         Write pipeline result arrays as sidecars.\n"
      << "  --verbose                        Print pipeline timing details.\n\n"
      << "DMAT files use the Directional format: `<columns> <rows>` followed by "
         "column-major values.\n";
}

} // namespace directional::cli
