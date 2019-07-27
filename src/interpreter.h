#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Interpreter {
 public:
  Interpreter() : memory(), memory_ptr(0), program(), program_ptr(0), bracket_stack(){};
  ~Interpreter() = default;

  void run_file(const char* filename) {
    std::string data = format_string(read_file(std::string{filename}));

    if (data.empty()) {
      std::cout << "Failed to open the file, or the file was empty, or the file did not contain a bf program.\n";
      return;
    }

    run(data);
  }

  void run_string(const char* src_code) {
    std::string data = format_string(std::string{src_code});

    if (data.empty()) {
      std::cout << "The input text is not a valid brainfuck program.\n";
      return;
    }

    run(data);
  }

 private:
  void reset() {
    memory = std::vector<unsigned char>(30000, 0);
    memory_ptr = 0;

    program = std::string{};
    program_ptr = 0;

    bracket_stack = std::stack<size_t>{};
  }

  void run(const std::string& data) {
    reset();
    program = data;

    while (0 <= program_ptr && program_ptr < program.size()) {
      switch (program[program_ptr]) {

        case '>':
          ++memory_ptr;
          break;

        case '<':
          --memory_ptr;
          break;

        case '+':
          ++memory[memory_ptr];
          break;

        case '-':
          --memory[memory_ptr];
          break;

        case '.':
          std::cout << memory[memory_ptr];
          break;

        case ',':
          memory[memory_ptr] = static_cast<unsigned char>(getchar());
          break;

        case '[':  // TODO
          bracket_stack.push(program_ptr);
          if (memory[memory_ptr] == 0) {
            for (auto left = bracket_stack.top();;) {
              ++program_ptr;
              if (program[program_ptr] == '[')
                bracket_stack.push(program_ptr);
              else if (program[program_ptr] == ']') {
                if (bracket_stack.top() == left) {
                  bracket_stack.pop();
                  break;
                } else {
                  bracket_stack.pop();
                }
              }
            }
          }
          break;

        case ']':
          if (memory[memory_ptr] != 0) {
            program_ptr = bracket_stack.top();
          } else {
            bracket_stack.pop();
          }
          break;

        default:
          std::cout << "Unexpected token: " << program[program_ptr] << std::endl;
          break;
      }

      ++program_ptr;
    }
  }

  std::string read_file(const std::string& filename) const {
    std::ifstream t(filename);

    // If the file was not opened or it is empty, then return an empty string.
    if (!t.is_open() || t.peek() == std::ifstream::traits_type::eof()) return std::string{};

    t.seekg(0, std::ios::end);

    size_t size = t.tellg();

    std::string buffer(size, ' ');

    t.seekg(0);
    t.read(&buffer[0], size);

    return buffer;
  }

  std::string format_string(const std::string& input) const {
    std::string buffer = input;

    auto NotValidToken = [](char ch) {
      return !(ch == '>' || ch == '<' || ch == '+' || ch == '-' || ch == '.' || ch == ',' || ch == '[' || ch == ']');
    };

    buffer.erase(std::remove_if(buffer.begin(), buffer.end(), NotValidToken), buffer.end());

    return buffer;
  }

  std::vector<unsigned char> memory;
  size_t memory_ptr;

  std::string program;
  size_t program_ptr;

  std::stack<size_t> bracket_stack;
};