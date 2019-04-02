cmake_minimum_required(VERSION 3.10)

project(Template)

add_subdirectory(testing)

# Code
add_library(code source/code.cc)
target_compile_features(code PRIVATE cxx_std_17)

# Test
add_executable(test source/test-code.cc)
target_link_libraries(test PRIVATE code testing)
target_compile_features(test PRIVATE cxx_std_17)
add_custom_target(run-tests ALL test)
