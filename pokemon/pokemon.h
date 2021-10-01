#ifndef POKEMON_H_
#define POKEMON_H_
#include "../defs.h"
#include "type.h"
#include "info.h"

typedef struct s_Pokemon* Pokemon;

Pokemon pokemonCreate(char* name, char* species, double height, double weight, int attack, Type type);
status pokemonFree(Pokemon pokemon);

#endif /* POKEMON_H_ */
