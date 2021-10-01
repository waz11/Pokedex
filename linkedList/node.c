#include "../linkedList/node.h"

#include <stdio.h>
#include <stdlib.h>

struct Node{
    void* element;
    Node next;
};

Node createNode(void* element, copy copy){
    if(element == NULL) return NULL;
    Node node = (Node) malloc(sizeof(struct Node));
	if(node == NULL) return NULL;
	node->element = copy(element);
	node->next = NULL;
    return node;
}

status freeNode(Node node, freeElement freeElement){
    freeElement(node->element);
    free(node);
    node = NULL;
    return SUCCESS;
}

void* getElement(Node node){
    return node->element;
}

Node getNext(Node node){
    return node->next;
}

status setNext(Node source, Node other){
    if(source == NULL) return FAILURE;
    source->next = other;
    return SUCCESS;
}

char* displayNode(Node node, printElement printElement){
	if(node==NULL) {
		printf("here!! \n");
		return "";

	}
	return printElement(node->element);
}


