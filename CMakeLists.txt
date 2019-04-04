cmake_minimum_required(VERSION 3.10)

project(Template)

add_subdirectory(testing)

add_library(settings INTERFACE)
target_compile_features(settings INTERFACE cxx_std_17)
target_compile_options(settings INTERFACE -pedantic -Wall -Werror)

# Code
add_library(code source/code.cc)
target_link_libraries(code PRIVATE settings)

# Test
add_executable(test source/test-code.cc)
target_link_libraries(test PRIVATE code testing settings)
add_custom_target(run-tests ALL test)

