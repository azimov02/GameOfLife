cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(gameOfLifeStep3 VERSION 1.0)
add_executable(gameOfLifeStep3 step3.c)
add_subdirectory(lib)
add_subdirectory(tests)
target_include_directories(${PROJECT_NAME} PUBLIC lib)
target_link_libraries(${PROJECT_NAME} board)
target_link_libraries(${PROJECT_NAME} readInput)
add_custom_target(
  doc ALL
  COMMAND $<$<CONFIG:Release>:${DOXYGEN_EXECUTABLE} ${doxyfile_in}>
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM
)