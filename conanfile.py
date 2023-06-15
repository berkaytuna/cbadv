from conan import ConanFile

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def build_requirements(self):
        self.requires("openssl/3.1.1")
        self.requires("boost/1.82.0")