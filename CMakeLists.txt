cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the path to MyLibrary
set(MYLIBRARY_DIR ${CMAKE_SOURCE_DIR}/dependency)

# Add the subdirectory for MyApp
add_subdirectory(project)
