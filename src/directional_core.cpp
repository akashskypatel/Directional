#include <directional/pipeline.h>

#ifdef _WIN32
#define DIRECTIONAL_EXPORT __declspec(dllexport)
#else
#define DIRECTIONAL_EXPORT
#endif

extern "C" DIRECTIONAL_EXPORT const char* directional_build_info() {
  return "Directional shared library core";
}
