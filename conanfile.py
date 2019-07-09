from conans import ConanFile, CMake

class TheTemplateConan(ConanFile):
    name = "TheTemplate"
    version = "0.1"
    #license = "<Put the package license here>"
    #author = "<Put your name here> <And your email here>"
    #url = "<Package recipe repository url here, for issues about the package>"
    description = "This package simply opens a window with SFML. It tests Conan, Cmake and SFML."
    #topics = ("<Put some tag here>", "<here>", "<and here>")

    settings = "os", "compiler", "build_type", "arch"
	# If this package has configure flags, they go here.
    options = {"shared": [True, False]}
    generators = "cmake"
    exports_sources = "src/*"

    # This is where all of the dependencies for the project go.
    # Others: ["glfw/3.2.1@bincrafters/stable", "sdl2/2.0.9@bincrafters/stable", "glad/0.1.29@bincrafters/stable"] etc.
    requires = "sfml/2.5.1@bincrafters/stable"

    # This is where the dependencies are configured.
    default_options = {"shared": False, "sfml:graphics": True, "sfml:window": True, "sfml:audio": False, "sfml:network": False}


    def configure_cmake(self):
        cmake = CMake(self)
        #cmake.definitions["SOME_DEFINITION"] = True
        cmake.configure(source_folder="src")
        return cmake

    def build(self):
        cmake = self.configure_cmake()
        cmake.build()

    def package(self):
        cmake = self.configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["TheTemplate"]