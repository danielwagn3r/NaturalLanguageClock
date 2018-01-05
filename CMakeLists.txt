cmake_minimum_required (VERSION 3.0)

project(NaturalLanguageClock)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SOURCE
  clock.c
)

set(HEADERS
  clock.h
)

add_executable(clock ${SOURCE} ${HEADERS})