#include <directional/core/Library.h>

extern "C" const char *directional_build_info() {
#if defined(DIRECTIONAL_SHARED)
  return "Directional shared library core";
#else
  return "Directional static library core";
#endif
}
