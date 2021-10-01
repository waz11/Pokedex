cmake_minimum_required(VERSION 3.20)
project(pokedex C)

set(CMAKE_C_STANDARD 99)

add_executable(pokedex defs.h linkedList/node.h linkedList/node.c linkedList/linkedList.h linkedList/linkedList.c pokemon/info.h pokemon/info.c pokemon/type.h pokemon/type.c pokemon/pokemon.h pokemon/pokemon.c test/test.h test/test.c main.c)