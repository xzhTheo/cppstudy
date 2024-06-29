cmake_minimum_required(VERSION 3.25)
PROJECT(STUDY)
set(CMAKE_CXX_STANDARD 17)
SET(SRC_LIST flatterbuffer_test.cpp)
include_directories ("/Users/theo.xu/Downloads/flatbuffer/flatbuffers/include") 

# MESSAGE(STATUS "this is BINARY DIR" ${STUDY_BINARY_DIR})
# MESSAGE(STATUS "this is SOURCE DIR" ${STUDY_SOURCE_DIR})
ADD_EXECUTABLE(xzh ${SRC_LIST})