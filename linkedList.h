#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "defs.h"
#include "node.h"

typedef struct LinkedList* LinkedList;

LinkedList createLinkedList(copy,freeElement,compare, printElement);
status destroyList(LinkedList);
status appendNode(LinkedList, void*);
status deleteNode(LinkedList, void*);
status displayList(LinkedList);
void* searchByKeyInList(LinkedList, void*);
int getSize(LinkedList list);

LinkedList copyList(LinkedList, copy);


#endif /* LINKEDLIST_H_ */
