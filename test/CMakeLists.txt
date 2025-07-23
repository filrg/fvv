cmake_minimum_required(VERSION 3.14)

project(fvvTests LANGUAGES C)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(fvv REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(fvv_test source/fvv_test.c)
target_link_libraries(fvv_test PRIVATE fvv::fvv)
target_compile_features(fvv_test PRIVATE c_std_11)
add_test(NAME fvv_test COMMAND fvv_test)

add_executable(fvv_math_test source/fvv_math_test.c)
target_link_libraries(fvv_math_test PRIVATE fvv::fvv)
target_compile_features(fvv_math_test PRIVATE c_std_11)
add_test(NAME fvv_math_test COMMAND fvv_math_test)

add_executable(fvv_bitstream_test source/fvv_bitstream_test.c)
target_link_libraries(fvv_bitstream_test PRIVATE fvv::fvv)
target_compile_features(fvv_bitstream_test PRIVATE c_std_11)
add_test(NAME fvv_bitstream_test COMMAND fvv_bitstream_test)

add_executable(fvv_syntax_test source/fvv_syntax_test.c)
target_link_libraries(fvv_syntax_test PRIVATE fvv::fvv)
target_compile_features(fvv_syntax_test PRIVATE c_std_11)
add_test(NAME fvv_syntax_test COMMAND fvv_syntax_test)

# ---- End-of-file commands ----

add_folders(Test)
