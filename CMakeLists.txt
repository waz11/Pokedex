cmake_minimum_required(VERSION 3.20)
project(pokedex C)

set(CMAKE_C_STANDARD 99)

add_executable(pokedex defs.h node.h node.c linkedList.h linkedList.c info.h info.c type.h type.c pokemon.h pokemon.c ./test/test.h ./test/test.c main.c)