#ifndef NODE_H_
#define NODE_H_

#include "defs.h"

typedef struct Node* Node;

Node createNode(void*, copy);
status freeNode(Node node, freeElement);

void* getElement(Node node);
Node getNext(Node node);

status setNext(Node source, Node other);
status setElement(Node node, void* element);

char* displayNode(Node node, printElement printElement);


#endif /* NODE_H_ */




