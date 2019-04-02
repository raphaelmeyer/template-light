# Testing Library
add_library(testing testing.cc)
target_include_directories(testing PUBLIC include)
target_compile_features(testing PRIVATE cxx_std_17)
