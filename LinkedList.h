#include <stdlib.h>
#include<stdbool.h>
typedef struct Node{
	void *data;
	struct Node* next;
} Node;

typedef struct LinkedList{
	struct Node *start;
	struct Node *end;
	int len;
	int type;
} LinkedList;

///ADD DOCUMENTATION

LinkedList ll_new(int type);
void ll_addNode(LinkedList *ll, void *value);

void ll_setNode(Node *ll, void *value);
void ll_removeLast(LinkedList *ll);
void ll_removeFirst(LinkedList *ll);
Node* ll_getNodeBefore(LinkedList *ll, Node *node);
void ll_freeNodes(LinkedList *ll);
void ll_cleanList(LinkedList *ll);
void ll_pushFront(LinkedList *ll, void *value);
Node* ll_getPtrFront(LinkedList *ll);
Node* ll_getPtrBack(LinkedList *ll);
Node* ll_containsPtr(LinkedList *ll, void* value);

Node* ll_getPtrContains(LinkedList *ll, void* value);
bool ll_isEmpty(LinkedList *ll);
int ll_getLength(LinkedList *ll);
void ll_debugPrint(LinkedList *ll);
