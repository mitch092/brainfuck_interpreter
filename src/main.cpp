#include "interpreter.h"

int main(int argc, char *argv[]) {
  if (((argc != 3) && (argc != 2)) || (strcmp(argv[1], "-h") == 0)) {
    std::cout << "This is a Brainfuck interpreter written in c++.\n"
              << "The default behaviour is to open up a file given on the command line.\n"
              << "If the -i option is passed, then the program will expect an entire brainfuck\n"
              << "program to be entered in the commandline as an argument.\n"
              << "This message is printed if the -h option is passed.\n"
              << "If -t1 is passed, then a hello world program is run.\n"
              << "If -t2 is passed, then a rot13 interactive program is run.\n";
    return EXIT_SUCCESS;
  }

  Interpreter intr;

  if (strcmp(argv[1], "-t1") == 0) {
    intr.run_file("../test_programs/test1.b");
  } else if (strcmp(argv[1], "-t2") == 0) {
    intr.run_file("../test_programs/test2.b");
  } else if (strcmp(argv[1], "-i") == 0) {
    intr.run_string(argv[2]);
  } else {
    intr.run_file(argv[1]);
  }

  return EXIT_SUCCESS;
}