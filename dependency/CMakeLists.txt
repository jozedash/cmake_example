cmake_minimum_required(VERSION 3.0)
project(MyDependency)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add library
add_library(MyDependency SHARED my_library2.cpp)

# Specify different output directories for different platforms
if(WIN32)
    set(PLATFORM_OUTPUT_DIR "Windows")
else()
    set(PLATFORM_OUTPUT_DIR "Linux")
endif()

set_target_properties(MyDependency PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/bin"
)

# Get all header files in the MyApp directory
file(GLOB_RECURSE HEADER_FILES "*.h" "*.hpp")

# Define the output directory
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/include)

# Create the output directory if it doesn't exist
file(MAKE_DIRECTORY ${OUTPUT_DIR})

# Copy all header files to the output directory
foreach(HEADER_FILE ${HEADER_FILES})
    file(COPY ${HEADER_FILE} DESTINATION ${OUTPUT_DIR})
endforeach()