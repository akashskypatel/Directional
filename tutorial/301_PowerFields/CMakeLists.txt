cmake_minimum_required(VERSION 3.21)
project(301_PowerFields)

add_executable(${PROJECT_NAME}_bin main.cpp)
target_link_libraries(${PROJECT_NAME}_bin PUBLIC tutorials polyscope directional)
directional_finalize_tutorial_target(${PROJECT_NAME}_bin)
