#include "CliCommands.h"

#include <ostream>

namespace directional::cli {

void print_usage(std::ostream &stream) {
  stream
      << "Directional native command line interface\n\n"
      << "Usage:\n"
      << "  directional info\n"
      << "  directional cross-field <input.obj|input.off> <output-field> [options]\n"
      << "  directional convert-field <input-field> <output-field> [options]\n"
      << "  directional remesh <input.obj|input.off> <output.obj|output.off> [options]\n"
      << "  directional --version\n"
      << "  directional --help\n\n"
      << "Field formats:\n"
      << "  crossfield  .vec or .txt; rows contain alpha and beta (six values).\n"
      << "  rosy        .rosy; two-line count/degree header and one alpha vector per face.\n"
      << "  rawfield    .rawfield; degree/count header and 3 * degree values per face.\n\n"
      << "Commands:\n"
      << "  info           Show native library build information.\n"
      << "  cross-field    Extract a smooth face-based 4-RoSy field.\n"
      << "  convert-field  Convert between crossfield, rosy, and rawfield formats.\n"
      << "  remesh         Remesh a triangle mesh, extracting a cross field when none is supplied.\n\n"
      << "cross-field options:\n"
      << "  --output-format <auto|crossfield|rosy|rawfield>\n"
      << "  --no-normalize-directions  Preserve computed direction magnitudes.\n"
      << "  --no-normalize             Backward-compatible alias.\n"
      << "  --no-matching              Skip edge matching and singularity analysis.\n"
      << "  --singularities <path>     Write singularities to a .sings file.\n"
      << "  --diagnostics-prefix <p>   Write field diagnostics as sidecars.\n"
      << "  --verbose                  Print processing details.\n\n"
      << "convert-field options:\n"
      << "  --input-format <auto|crossfield|rosy|rawfield>\n"
      << "  --output-format <auto|crossfield|rosy|rawfield>\n"
      << "  --mesh <input.obj|input.off>  Required when beta must be reconstructed from normals.\n"
      << "  --degree <2|4>                 Rawfield output degree (default 4).\n\n"
      << "remesh options:\n"
      << "  --field <path>                  Use crossfield, rosy, or rawfield input.\n"
      << "  --field-format <auto|crossfield|rosy|rawfield>\n"
      << "  --raw-field <path>              Legacy degree-4 rawfield input alias.\n"
      << "  --primary-directions <path>     Legacy #F x 3 DMAT direction matrix.\n"
      << "  --secondary-directions <path>   Legacy second #F x 3 DMAT matrix.\n"
      << "  --length-ratio <value>          Target edge-length ratio (default 0.02).\n"
      << "  --no-integral-seamless          Disable integral seamless constraints.\n"
      << "  --round-seams                   Round seam values during integration.\n"
      << "  --no-normalize-directions       Preserve supplied direction magnitudes.\n"
      << "  --diagnostics-prefix <p>        Write pipeline result arrays as sidecars.\n"
      << "  --verbose                       Print pipeline timing details.\n";
}

} // namespace directional::cli
