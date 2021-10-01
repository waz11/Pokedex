#include "../test/test.h"
#include "../test/intFunctions.h"
#include "../node.h"
#include "../linkedList.h"
#include "../info.h"
#include "../type.h"
#include "../pokemon.h"


void test_node(){
	int val1 = 1;
	Node node1 = createNode((void*)(&val1), copyInt);
	printf("%d\n",*(int*)(getElement(node1)));
	freeNode(node1, freeInt);
}

void test_linked_List(){
	LinkedList list = createLinkedList(copyInt, freeInt, compareInt, printInt);
	int val1=1, val2=2, val3=3;
	void *e1 = &val1, *e2=&val2, *e3=&val3;
	appendNode(list, e1);
	appendNode(list, e2);
	appendNode(list, e3);
	displayList(list);
	deleteNode(list, e3);
	displayList(list);
	destroyList(list);
}

void test_info(){
	Info info = infoCreate(1.1, 2.2, 30);
	infoDisplay(info);
	infoDestory(info);
}

void test_type(){
	Type type = typeCreate("Type_1");
	printf("effective size:%d\n",getEffectiveAgainstMeSize(type));
	Type t1 = typeCreate("effect_1");
	addEffeciveAgainstMe(type, t1);
	printf("effective size:%d\n",getEffectiveAgainstMeSize(type));
	Type t2 = typeCreate("effect_2");
	addEffeciveAgainstMe(type, t2);
	printf("effective size:%d\n",getEffectiveAgainstMeSize(type));
	getEffectiveAgainstMe(type);

	deleteEffectiveAgainstMe(type, t1);
	printf("\neffective size:%d\n",getEffectiveAgainstMeSize(type));
	getEffectiveAgainstMe(type);

	deleteEffectiveAgainstMe(type, t2);
	printf("\neffective size:%d\n",getEffectiveAgainstMeSize(type));
	getEffectiveAgainstMe(type);

	typeFree(t1);
	typeFree(t2);
	typeFree(type);
}

void test_pokemon(){
	Type fire = typeCreate("Fire"),
			water = typeCreate("Water"),
			electric = typeCreate("Electric"),
			grass = typeCreate("Grass");

	addEffeciveAgainstMe(fire, water);
	addEffeciveAgainstOthers(fire, grass);
	addEffeciveAgainstOthers(fire, electric);
	addEffeciveAgainstOthers(electric, water);


	Pokemon pikachu = pokemonCreate("Pikachu", "MousePokemon", 0.4, 6, 55, electric),
			charmander = pokemonCreate("Charmander", "LizradPokemon", 0.5, 8.5, 52, fire),
			ponyta = pokemonCreate("Ponyta", "FireHorsePokemon", 1.0, 30.0, 85, fire),
			squirtle = pokemonCreate("Squirtle", "TinyTurtlePokemon", 0.5, 9, 48, water),
			psyduck = pokemonCreate("Psyduck", "DuckPokemon", 0.8, 19.6, 52, water);

	pokemonFree(pikachu);
	pokemonFree(charmander);
	pokemonFree(ponyta);
	pokemonFree(squirtle);
	pokemonFree(psyduck);
	typeFree(fire);
	typeFree(water);
	typeFree(electric);
	typeFree(grass);

}




