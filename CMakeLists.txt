cmake_minimum_required(VERSION 3.27)
project(Hospedagem C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Hospedagem
        APRESENTACAO.c
        APRESENTACAO.h
        Cliente.h
        DATA.h
        QUARTO.c
        QUARTO.h
        RESERVA.c
        RESERVA.h
        Cliente.c
        DATA.c
        main.c
        main.c
        main.c
        main.c
)
