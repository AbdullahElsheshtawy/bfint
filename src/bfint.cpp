#include "bfint.h"
#include <filesystem>
#include <fstream>

int main(int argc, char **argv) {
  if (argc == 2) {
    if (std::filesystem::exists(argv[1])) {
      std::fstream file{std::filesystem::path(argv[1])};
      std::string program((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());
      file.close();
      interpreter interpreter;
      interpreter.interpret(program);
    }
    else std::cerr << "FATAL: File " << argv[1] << " Does not exist\n";
    return 1;
  } else {

    while (true) {
      std::string program;
      std::cin >> program;
      interpreter interpreter;
      interpreter.interpret(program);
      std::cout << "\n Finished interpreting on the fly\n" << std::endl;
    }
  }
  return 0;
}
