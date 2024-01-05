cmake_minimum_required(VERSION 3.24)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(
        ${GTK4_INCLUDE_DIRS}
        E:\\untitled2\\include
)

link_directories(
        ${GTK4_LIBRARY_DIRS}
        E:\\untitled2\\lib
)

link_libraries(libmysql)

add_executable(untitled2 main.c
        setMysql.h
        setMysql.c
        readText.h
        readText.c
        review.h
        review.c
        recite.c
        recite.h
        dictation.h
        dictation.c
)

target_link_libraries(untitled2 ${GTK4_LIBRARIES} libmysql)
