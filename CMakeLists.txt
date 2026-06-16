cmake_minimum_required(VERSION 3.10.0)
project(TerminalDungeonGame VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES 
    "src/*.c"
    "src/*.cpp"
)

add_subdirectory(external/googletest)

add_library(
    TerminalDungeonGameLib
    ${SOURCE_FILES}
    src/Consumable.cpp
    header/ClosestToDyingTarStrat.h
    src/ClosestToDyingTarStrat.cpp
)

add_executable(${PROJECT_NAME} main.cpp)

add_executable(CharacterTest tests/CharacterTest.cpp)
add_executable(WizardTest tests/WizardTest.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    TerminalDungeonGameLib
)

target_link_libraries(
    CharacterTest
    PRIVATE
    TerminalDungeonGameLib
    GTest::gtest_main
)

target_include_directories(
    CharacterTest
    PRIVATE
        ${CMAKE_SOURCE_DIR}/header
        ${CMAKE_SOURCE_DIR}/src
)


target_link_libraries(
    WizardTest
    PRIVATE
    TerminalDungeonGameLib
    GTest::gtest_main
)

target_include_directories(
    WizardTest
    PRIVATE
        ${CMAKE_SOURCE_DIR}/header
        ${CMAKE_SOURCE_DIR}/src
)


target_include_directories(
    TerminalDungeonGameLib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/header
        ${CMAKE_SOURCE_DIR}/src
)

enable_testing()

include(GoogleTest)

gtest_discover_tests(CharacterTest)
gtest_discover_tests(WizardTest)