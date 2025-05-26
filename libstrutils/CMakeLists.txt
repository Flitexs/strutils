project(strUtils LANGUAGES C)

set(CMAKE_C_STANDARD 17)

# Add a static library named "strUtils" that will be built from the source file "strUtils.c"
add_library(${PROJECT_NAME} STATIC
    strUtils.c
)

# Specify the include directories for the "strUtils" library
# This makes the "include" folder available to any code that uses this library ?????
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
