cmake_minimum_required(VERSION 3.16)

project(ObjectFrame LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCES
    src/init_jobj.c
    src/init_jobj.h
    src/jobj.c
    src/jobj.h
    src/main.c
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

