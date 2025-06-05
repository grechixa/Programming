cmake_minimum_required(VERSION 3.10)
project(LR_5 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(LR_5
  main.c
  data.c
  data.h
)

install(TARGETS LR_5 DESTINATION bin)
