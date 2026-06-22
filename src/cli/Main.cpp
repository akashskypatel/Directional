#include "CliCommands.h"

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  try {
    if (argc <= 1) {
      directional::cli::print_usage(std::cout);
      return 0;
    }

    const std::string command = argv[1];
    if (command == "--help" || command == "-h" || command == "help") {
      directional::cli::print_usage(std::cout);
      return 0;
    }

    if (command == "--version" || command == "-V") {
      directional::cli::print_version(std::cout);
      return 0;
    }

    if (command == "info") {
      return directional::cli::run_info(std::cout);
    }

    if (command == "cross-field") {
      return directional::cli::run_cross_field(argc, argv);
    }

    if (command == "convert-field") {
      return directional::cli::run_convert_field(argc, argv);
    }

    if (command == "remesh") {
      return directional::cli::run_remesh(argc, argv);
    }

    std::cerr << "directional-cli: unknown command: " << command << '\n';
    std::cerr << "Run `directional --help` for usage.\n";
    return 2;
  } catch (const std::exception &error) {
    std::cerr << "directional-cli: error: " << error.what() << '\n';
    return 1;
  }
}
