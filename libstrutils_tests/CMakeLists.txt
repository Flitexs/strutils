project(strUtilsTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# Add an executable named "strUtilsTests" that will be built from the source file "catch_strutils.cpp"
add_executable(${PROJECT_NAME}
    test_strtoint.cpp
)

# Link the Catch2 testing framework to the "strUtilsTests" executable
# This provides the main function and testing utilities from Catch2
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain strUtils)
