cmake_minimum_required(VERSION 3.0)
project(CrossCompilableApp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify different output directories for different platforms
if(WIN32)
    set(PLATFORM_OUTPUT_DIR "Windows")
else()
    set(PLATFORM_OUTPUT_DIR "Linux")
endif()

# Link to dependency
set(DEPENDENCY_DIR "${CMAKE_SOURCE_DIR}/dependency/build/${PLATFORM_OUTPUT_DIR}")
include_directories(${DEPENDENCY_DIR}/include)
link_directories(${DEPENDENCY_DIR}/lib)


# Add the executable
add_executable(CrossCompilableApp main.cpp)

set_target_properties(CrossCompilableApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/bin"
)

# Add library
add_library(MyLibrary SHARED my_library.cpp)

set_target_properties(MyLibrary PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/bin"
)

# Link the library to the executable
target_link_libraries(CrossCompilableApp MyLibrary MyDependency)

file(COPY "${DEPENDENCY_DIR}/lib"
    DESTINATION "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}")
file(COPY "${DEPENDENCY_DIR}/bin"
    DESTINATION "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}")

add_custom_target(copy_dll ALL
    DEPENDS CrossCompilableApp
)
# add_custom_command(target CrossCompilableApp
# POST_BUILD
#     COMMAND &{CMAKE_COMMAND2} -E Copy
#     "${DEPENDENCY_DIR}/bin/MyDependency*"
#     "${CMAKE_BINARY_DIR}/${PLATFORM_OUTPUT_DIR}/bin/"
# )