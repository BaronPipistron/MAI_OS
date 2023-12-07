cmake_minimum_required(VERSION 3.14)

project(lab3)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES FALSE ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME}_lib ${SOURCES})

target_include_directories(${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_compile_options(${PROJECT_NAME}_lib PUBLIC "-Wall" "-Werror")
target_link_options(${PROJECT_NAME}_lib PUBLIC "-lrt" "-pthread")

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED ON)


add_executable(${PROJECT_NAME}_run_exe run_files/run_parent.cpp)
target_link_libraries(${PROJECT_NAME}_run_exe ${PROJECT_NAME}_lib)
                      
add_executable(${PROJECT_NAME}_run_child run_files/run_child.cpp)
target_link_libraries(${PROJECT_NAME}_run_child ${PROJECT_NAME}_lib)