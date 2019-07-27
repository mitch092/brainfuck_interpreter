# Brainfuck interpreter
This is a Brainfuck interpreter written in C++.

# Instructions
Type "brainfuck_interpreter.exe -h" in the directory containing the exe for instructions on how to run this program.

# Test Results
So far, the "Hello World!" and rot13 programs work flawlessly.

# Implementation Difficluties
I used https://en.wikipedia.org/wiki/Brainfuck as a reference. I implemented the square bracket matcher using std::stack. The code for that part is messy and possibly bug-ridden, 
but otherwise everything else was straightforward.