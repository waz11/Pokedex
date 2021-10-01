#include "../linkedList/linkedList.h"

#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
	Node head;
	Node last;
	int size;

	copy copy;
	freeElement freeElement;
	compare compare;
	printElement print;
};

LinkedList createLinkedList(copy copy, freeElement freeElement, compare compare, printElement print){
	if(copy==NULL || freeElement==NULL || compare==NULL || print==NULL) return NULL;
	LinkedList list = (LinkedList)malloc(sizeof(struct LinkedList));
	if(list == NULL) return NULL;
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
	list->copy = copy;
	list->freeElement = freeElement;
	list->compare = compare;
	list->print = print;
	return list;
}

status destroyList(LinkedList list){
	if(list == NULL) return FAILURE;
	Node curr = list->head;
	while(curr != NULL){
		Node next = getNext(curr);
		freeNode(curr, list->freeElement);
		curr = next;
	}
	free(list);
	return SUCCESS;
}

status appendNode(LinkedList list, void* element){
	if(list==NULL || element == NULL) return FAILURE;
	Node node = createNode(element, list->copy);
	if(list->size == 0){
		list->head = node;
		list->last = node;
	}else{
		setNext(list->last, node);
		list->last = node;
	}
	list->size++;
	return SUCCESS;
}

status deleteNode(LinkedList list, void* element){
	if(list==NULL || element == NULL) return FAILURE;
	Node curr = list->head;
	Node prev = NULL;
	bool found = false;

	while(curr!=NULL && found==false){
		int compareResult = list->compare(getElement(curr), element);
		if(compareResult == 0){
			found=true;
			if(prev==NULL) list->head = getNext(curr);
			else setNext(prev, getNext(curr));
			freeNode(curr, list->freeElement);
			list->size--;
			return SUCCESS;
		}
		else{
			prev = curr;
			curr = getNext(curr);
		}
	}
	return FAILURE;
}

status displayList(LinkedList list){
	if(list == NULL) return FAILURE;
	Node curr = list->head;
	while(curr != NULL){
		printf("%s ",displayNode(curr, list->print));
		curr=getNext(curr);
	}
	return SUCCESS;
}

void* searchByKeyInList(LinkedList list, void* element){
	if(list==NULL || element == NULL) return NULL;
	Node curr = list->head;
	while(curr != NULL){
		if(list->compare(getElement(curr), element) != 0) return getElement(curr);
		curr = getNext(curr);
	}
	return NULL;
}

LinkedList copyList(LinkedList list, copy source){
	return NULL;
}

int getSize(LinkedList list){
	return list->size;
}
