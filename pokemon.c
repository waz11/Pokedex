#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include "info.h"
#include "type.h"

struct s_Pokemon{
	char* name;
	char* species;
	Type type;
	Info info;
};

Pokemon pokemonCreate(char* name, char* species, double height, double weight, int attack, Type type){
	if(name==NULL) return NULL;
	Pokemon pokemon = (Pokemon) malloc(sizeof(struct s_Pokemon));
	if(pokemon == NULL) {
		free(pokemon);
		return NULL;
	}

	pokemon->name = (char*) malloc(sizeof(name)+1);
	pokemon->species = (char*) malloc(sizeof(species)+1);
	if(pokemon->name == NULL || pokemon->species == NULL){
		free(pokemon->name);
		free(pokemon->species);
		free(pokemon);
		return NULL;
	}
	strcpy(pokemon->name, name);
	strcpy(pokemon->species, species);

	pokemon->type=type;
	increase_cnt_instances(type);

	pokemon->info = infoCreate(height, weight, attack);
	return pokemon;
}

status pokemonFree(Pokemon pokemon){
	if(pokemon==NULL) return SUCCESS;
	free(pokemon->name);
	free(pokemon->species);
	decrease_cnt_instances(pokemon->type);
	infoDestory(pokemon->info);
	free(pokemon);
	pokemon=NULL;
	return SUCCESS;
}
