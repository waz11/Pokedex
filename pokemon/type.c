#include "type.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../linkedList/linkedList.h"

struct Type{
	char* name;
	LinkedList effective_against_me;
	LinkedList effective_against_others;
	int cnt_instances;
};

void* copyTypePointer(void* element){
	Type type = (Type)element;
	return type;
}
void freeTypePointer(void* type){

}
int compareTypePointer(void* source, void* other){
	Type type1 = (Type)source, type2 = (Type)other;
	return type1==type2 ? 0:-1;
}
char* printTypePointer(void* type){
	return getTypeName((Type)type);
}

Type typeCreate(char* name){
	Type type = (Type)malloc(sizeof(struct Type));
	if(type==NULL) return NULL;
	type->name = (char*)malloc(sizeof(name)+1);
	if(type->name==NULL){
		free(type);
		return NULL;
	}
	strcpy(type->name, name);
	type->cnt_instances = 0;
	type->effective_against_me = createLinkedList(copyTypePointer, freeTypePointer, compareTypePointer, printTypePointer);
	type->effective_against_others = createLinkedList(copyTypePointer, freeTypePointer, compareTypePointer, printTypePointer);
	return type;

}
char* getTypeName(Type type){
	return type->name;
}
status typeFree(Type type){

	if(type==NULL) return SUCCESS;
	free(type->name);
	destroyList(type->effective_against_me);
	destroyList(type->effective_against_others);
	free(type);
	return SUCCESS;
}
//void* copyType(void* element){
//	Type source = (Type)element;
//	Type other = (Type)malloc(sizeof(struct Type));
//	if(other==NULL) return NULL;
//	other->name = (char*)malloc(sizeof(source->name)+1);
//	if(other->name==NULL){
//		free(other);
//		return NULL;
//	}
//	other->cnt_instances = source->cnt_instances;
//	other->effective_against_me = (Type*)malloc(sizeof(source->effective_against_me));
//	if(other->effective_against_me == NULL){
//		free(other->name);
//		free(other);
//		return NULL;
//	}
//	other->effective_against_me = copyList(source->effective_against_me, copyType);
//	other->effective_against_others = copyList(source->effective_against_others, copyType);
//
//	if(other->effective_against_me == NULL || other->effective_against_others == NULL){
//		free(other->effective_against_others);
//		free(other->effective_against_me);
//		free(other->name);
//		free(other);
//		return NULL;
//	}
//	return other;
//}

status addEffeciveAgainstMe(Type source, Type other){
	appendNode(source->effective_against_me, other);
	return SUCCESS;
}
status deleteEffectiveAgainstMe(Type source, Type other){
	deleteNode(source->effective_against_me, other);
	return SUCCESS;
}
void getEffectiveAgainstMe(Type type){
	displayList(type->effective_against_me);
}
int getEffectiveAgainstMeSize(Type type){
	return getSize(type->effective_against_me);
}

status addEffeciveAgainstOthers(Type source, Type other){
	appendNode(source->effective_against_others, other);
		return SUCCESS;
}
void getEffectiveAgainstOthers(Type type){
	displayList(type->effective_against_others);
}
status deleteEffectiveAgainstOthers(Type source, char* other){
	deleteNode(source->effective_against_others, other);
	return SUCCESS;
}
int getEffectiveAgainstOthersSize(Type type){
	return getSize(type->effective_against_others);
}

status increase_cnt_instances(Type type){
	if(type==NULL) return FAILURE;
	type->cnt_instances++;
	return SUCCESS;
}
status decrease_cnt_instances(Type type){
	if(type==NULL) return FAILURE;
	type->cnt_instances--;
	return SUCCESS;
}

