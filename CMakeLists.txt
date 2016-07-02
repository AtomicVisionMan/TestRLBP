cmake_minimum_required(VERSION 2.8)
project(TestRLBP)

ADD_EXECUTABLE(rlbp main.cpp)

find_package(OpenCV REQUIRED)
message(STATUS ${OpenCV_LIBS})
message(WARNING ${OpenCV_INCLUDE_DIRS})

IF(OpenCV_FOUND)
  TARGET_LINK_LIBRARIES(rlbp ${OpenCV_LIBS})
ENDIF()

