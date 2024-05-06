cmake_minimum_required(VERSION 3.22)


PROJECT(APPLICATION)



set(CMAKE_CXX_STANDARD 17)

include_directories(inc/ utils/)

set(SOURCE
src/Session_Application.cpp
)

add_executable(application   ${SOURCE})