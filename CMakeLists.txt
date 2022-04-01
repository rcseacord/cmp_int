cmake_minimum_required(VERSION 3.0)
project(cmp_int)
include(CTest)
set (CMAKE_BUILD_TYPE Debug)

#set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
#set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set(TEST_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/test")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(external)
#add_subdirectory(src)
add_subdirectory(test)


#enable_testing()

