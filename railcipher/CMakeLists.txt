cmake_minimum_required(VERSION 3.26)
project(railcipher C)

set(CMAKE_C_STANDARD 23)

add_executable(railcipher railcipher.c
        encryption.c decryption.c)
