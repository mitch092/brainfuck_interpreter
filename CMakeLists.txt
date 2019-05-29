cmake_minimum_required (VERSION 3.11)
project ("sfml_template")

####This entire section should be left alone. 
## This entire if block either calls Cmake from Conan, or calls Conan from Cmake.
# If I am building the package with Conan, I call Cmake from Conan with conan_basic_setup().
if(CONAN_EXPORTED)
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	conan_basic_setup(TARGETS)
# If I am building the package with Cmake (like in Visual Studio Community), then I call conan_cmake_run() which runs Conan.
else()
	if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
		message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
		file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.13/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
	endif()
	include(${CMAKE_BINARY_DIR}/conan.cmake)
	conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)
endif()
## If Visual Studio had first class support for Conan like it does for Cmake, then the else() branch would be unecessary.





#### This is where the Cmake code for the project goes.
add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/main.cpp")
#target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/includes")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::sfml)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)