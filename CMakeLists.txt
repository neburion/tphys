cmake_minimum_required(VERSION 3.20)
project(terminal-2d-physics)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# ===================================================================================
# Sources
# ===================================================================================
file(GLOB_RECURSE SRC src/**/*.cpp src/*.cpp)
file(GLOB_RECURSE TEST_FILES tests/*.cpp)
list(FILTER SRC EXCLUDE REGEX "src/main.cpp")
# ===================================================================================
# Release Binary
# ===================================================================================
add_executable(engine src/main.cpp ${SRC})
target_include_directories(engine PRIVATE include)
target_link_libraries(engine PRIVATE ncurses)
target_compile_options(engine PRIVATE -O2 -DNDEBUG)
# ===================================================================================
# Debug Binary
# ===================================================================================
add_executable(dbg-engine src/main.cpp ${SRC})
target_include_directories(dbg-engine PRIVATE include)
target_link_libraries(dbg-engine PRIVATE ncurses)
target_compile_options(dbg-engine PRIVATE -g -Wall -Wextra -Wpedantic -fsanitize=undefined,address,leak)
target_link_options(dbg-engine PRIVATE -fsanitize=undefined,address,leak)
# ===================================================================================
# GTest
# ===================================================================================
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)
# ===================================================================================
# Test Binary
# ===================================================================================
add_executable(test-engine ${TEST_FILES} ${SRC})
target_include_directories(test-engine PRIVATE include)
target_link_libraries(test-engine PRIVATE ncurses GTest::gtest_main)
target_compile_options(test-engine PRIVATE -g -Wall -Wextra -Wpedantic -fsanitize=undefined,address,leak)
target_link_options(test-engine PRIVATE -fsanitize=undefined,address,leak)
include(GoogleTest)
gtest_discover_tests(test-engine)
