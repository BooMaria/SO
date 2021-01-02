cmake_minimum_required(VERSION 3.17)
project(Jack C)

set(CMAKE_C_STANDARD 99)

add_executable(Jack servidor.c servidor.h servidorDedicat.c servidorDedicat.h until.c until.h llistaEstacions.c llistaEstacions.h mensaje.c mensaje.h fitxer.c fitxer.h semaphore_v2.h)