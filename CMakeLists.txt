cmake_minimum_required(VERSION 3.16)

project(StackBasedVM VERSION 2.0.0 LANGUAGES C)

add_executable(tests tests/test_simulator.c)
target_compile_features(tests PRIVATE cc)
