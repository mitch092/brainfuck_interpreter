# sfml-template
This is a simple project skeleton/template that uses Conan and Cmake in order to automatically download, 
build and link external dependencies for C++ projects. Other package managers for other languages, such as Java's Gradle
or Rust's Cargo, are also build systems. Conan, on the other hand, is a package manager but it is not a build system, so Cmake (or some other build system)
needs to be integrated. Also, there is no tool or program (that I know of) that writes conanfiles and cmakelists.txt for me, so after painstakingly writing them 
myself, I am just going to push it here on Github and fork it whenever I want to start a new project.

This skeleton could either be used to make programs or libraries. The benefit of having a conanfile.py as opposed to a conanfile.txt
is that conanfile.py allows libraries to be packaged into conan packages and included into other conan projects.

# Requirements
There are a few dependencies that must be installed on the system before this template can work:
1. Python must be installed. My version is 3.7.3. Don't know if version 2 will work or not; haven't tested.
1. Conan must be installed via pip.
1. I recommend adding "bintray" to Conan's list of remotes. The test program that uses SFML requires it.
1. Cmake is definitely required.
1. Some type of compiler such as Visual Studio's compiler, GCC, Clang, etc. I haven't tested this on Linux or OSX, but it works on Windows.

# Areas of Interest
* In the conanfile.py, there is a line called "requires". All project dependencies go here, either as a single string or as an array of
strings. 
* In cmakelists.txt, the second half of the file is where I have added my project's source code files (.h/.cpp/.cxx/.c) to a 
cmake target. target_link_libraries needs to be updated manually whenever new dependencies are added to the "requires" line
in the conanfile.py.
