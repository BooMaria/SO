cmake_minimum_required(VERSION 3.17)
project(Wendy C)

set(CMAKE_C_STANDARD 99)

add_executable(Wendy servidor.c servidor.h servidorDedicat.c until.c jpg.c mensaje.c fitxer.c semaphore_v2.h servidorDedicat.h until.h fitxer.h mensaje.h jpg.h)