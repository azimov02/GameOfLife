cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(gameOfLifeStep3 VERSION 1.0)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(gameOfLifeStep3 step3.c)
add_subdirectory(lib)
add_subdirectory(tests)
add_custom_target(
  doc ALL
  COMMAND doxygen Doxyfile
  VERBATIM
)
target_include_directories(${PROJECT_NAME} PUBLIC lib)
target_link_libraries(${PROJECT_NAME} board)
target_link_libraries(${PROJECT_NAME} readInput)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
