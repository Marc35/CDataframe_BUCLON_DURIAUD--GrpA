cmake_minimum_required(VERSION 3.27)
project(CDataframe_BUCLON_DURIAUD__GrpA_main C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDataframe_BUCLON_DURIAUD__GrpA_main
        cd.c
        cd.h
        colonne.c
        colonne.h
        liste.c
        liste.h
        main.c
        test.c
        help_functions.c
        help_functions.h)
