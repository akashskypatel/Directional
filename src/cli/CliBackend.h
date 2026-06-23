#pragma once

#include <string>
#include <vector>

namespace directional::cli {

/** Execute the Directional CLI using arguments that exclude argv[0]. */
int run_cli(const std::vector<std::string> &arguments);

/** Execute the Directional CLI using a conventional argc/argv array. */
int run_cli(int argc, char **argv);

} // namespace directional::cli
