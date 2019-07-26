# sfml-template
This is a simple project skeleton/template that builds a test SFML app using Cmake and Conan.

# Requirements
There are a few dependencies that must be installed on the system before this test can work:
1. Python 
1. Conan 
1. Cmake
1. Add "bintray" to Conan's list of remotes. The test program that uses SFML requires it.
1. A compiler such as Visual Studio's compiler, GCC, Clang, etc. Tested on Windows.

# Areas of Interest
* In the conanfile.py, there is a line called "requires". All external project dependencies go here, either as a single string or as an array of
strings. 
* In cmakelists.txt, target_link_libraries needs to be updated manually whenever new dependencies are added to the "requires" line
in the conanfile.py.
