# Specify the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Define the project name and the languages it uses (C and C++)
project(StrUtils LANGUAGES C CXX)

# Set the C standard to C17 and the C++ standard to C++23
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)

# Include the FetchContent module, which allows us to download and use external dependencies
Include(FetchContent)

# Declare the Catch2 testing framework as an external dependency
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git # URL of the Catch2 Git repository
  GIT_TAG        v3.8.1                                # Specific version (tag) of Catch2 to use
)

# Download and make the Catch2 library available for use in the project
FetchContent_MakeAvailable(Catch2)


add_subdirectory(libstrutils)
add_subdirectory(libstrutils_tests)
