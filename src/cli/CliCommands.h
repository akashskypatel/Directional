#pragma once

#include <iosfwd>

namespace directional::cli {

void print_usage(std::ostream &stream);
void print_version(std::ostream &stream);
int run_info(std::ostream &stream);
int run_cross_field(int argc, char **argv);
int run_convert_field(int argc, char **argv);
int run_remesh(int argc, char **argv);

} // namespace directional::cli
