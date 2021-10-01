#include <stdlib.h>
#include <stdio.h>

#include "test/test.h"
#include "type.h"

/* commands:
gcc -g -Wall defs.h node.h node.c linkedList.h linkedList.c info.h info.c type.h type.c pokemon.h pokemon.c ./test/test.h ./test/test.c main.c -o ./test/test
valgrind --tool=memcheck --leak-check=yes ./test/test
 */

void printMenu();

int main(){
	test_node();
	test_linked_List();
	test_info();
	test_type();
	test_pokemon();

	//	printMenu();
	printf("ok!");
	return 0;
}

void printMenu(){
	printf("Please choose one of the following numbers:\n");
	printf("1 : Print all Pokemons\n");
	printf("2 : Print all Pokemons types\n");
	printf("3 : Add type to effective against me list\n");
	printf("4 : Add type to effective against others list\n");
	printf("5 : Remove type from effective against me list\n");
	printf("6 : Remove type from effective against others list\n");
	printf("7 : Print Pokemon by name\n");
	printf("8 : Print Pokemons by type\n");
	printf("9 : Exit\n");
}
