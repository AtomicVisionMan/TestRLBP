cmake_minimum_required(VERSION 2.8)
project(TestRLBP)

ADD_EXECUTABLE(rlbp main.cpp LBP.cpp)

find_package(OpenCV REQUIRED)
message(STATUS ${OpenCV_LIBS})
message(WARNING ${OpenCV_INCLUDE_DIRS})

set( FFTW_INCLUDE_DIRS /usr/local/include)
message(STATUS ${FFTW_INCLUDE_DIRS})
find_path(FFTW_INCLUDE_DIR fftw3.h  ${FFTW_INCLUDE_DIRS})
find_library(FFTW_LIBRARY fftw3 ${FFTW_LIBRARY_DIRS})

message(STATUS ${FFTW_INCLUDE_DIRS})
message(WARNING ${FFTW_LIBRARY_DIRS})
message(WARNING ${FFTW_LIBRARY})

IF(OpenCV_FOUND)
  TARGET_LINK_LIBRARIES(rlbp ${OpenCV_LIBS} ${FFTW_LIBRARY})
ENDIF()

