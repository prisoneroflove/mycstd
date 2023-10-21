#include <stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include "LinkedList.h"

LinkedList ll_new(int type){
	LinkedList ll;
	ll.start = NULL;
	ll.end = NULL;
	ll.len = 0;
	if(type <= 2 && type >= 0){
		ll.type = type;
	}else{
		printf("\nFATAL ERROR:TYPE BIG\n");
		exit(0);

	}
	return ll;
}

void ll_setNode(Node *node, void *value){
	node->data = value;
}
void ll_addNode(LinkedList *ll, void *value){
	if(ll->start == NULL){
		ll->start = (Node*) malloc(sizeof(Node));
		if(ll->start != NULL){
			ll->start->next = NULL;
			ll_setNode(ll->start,value);
			ll->end = ll->start;
			ll->len += 1;
		}else{
			puts("Error on ll_addNode, couldnt malloc for start");
		}
	}else{
		ll->end->next = (Node*) malloc(sizeof(Node));
		if(ll->end->next != NULL){
			ll->end = ll->end->next;
			ll->end->next = NULL;
			ll_setNode(ll->end,value);
			ll->len += 1;
		}else{
			puts("Error on ll_addNode, couldnt malloc for end");
		}
	}
}

void ll_freeNodes(LinkedList *ll) {
    Node* node = ll->start;
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
}

void ll_cleanList(LinkedList *ll) {
    if (ll->start == NULL) {
        // List is already empty, nothing to clean
        return;
    }
    
    ll_freeNodes(ll);
    ll->start = NULL;
    ll->end = NULL;
    ll->len = 0;
}

void ll_pushFront(LinkedList *ll, void *value) {
    Node *n = malloc(sizeof(Node));
    if (n != NULL) {
        n->data = value;
        n->next = ll->start;
        ll->start = n;
        ll->len += 1;
    } else {
        printf("ERROR: Couldn't allocate memory for ll_pushFront\n");
    }
}


Node* ll_getPtrFront(LinkedList *ll){
	return ll->start;
}
Node* ll_getPtrBack(LinkedList *ll){
	return ll->end;
}

void ll_removeFirst(LinkedList *ll){
	if(ll->start != NULL){
		Node *node = ll->start;
		ll->start = ll->start->next;
		ll->len -= 1;
		free(node);
	}else{
		puts("ERROR: NO NODES TO PUT OUT first");
	}
}

void ll_removeLast(LinkedList *ll){
	if(ll->end != NULL){
		Node *node = ll_getNodeBefore(ll, ll->end);
		free(ll->end);
		ll->end = node;
		ll->end->next = NULL;
		ll->len -= 1;
	}else{
		puts("ERROR: NO NODE TO PUT OUT last");
	}
}

Node* ll_getNodeBefore(LinkedList *ll, Node *node){
	Node* nod = ll->start;
	while(nod != NULL){
		if(nod->next == node){
			return nod;
		}
		nod = nod->next;
	}
	return NULL;
}

Node* ll_containsPtr(LinkedList *ll, void *value){
	Node* node = ll->start;
	while(node != NULL){
		switch(ll->type){
			case 0:
				if(*((int*)node->data) == *((int*)value)){
					return node;
				}
				break;
			case 1:
				if(*((float*)node->data) == *((float*)value)){
					return node;
				}
				break;
			case 2:
				if (*((char*) node->data) == *((char*)value)){
					return node;
				}
				break;
			default:
				printf("\nYO BUG IN CODE\n");
		}
		node = node->next;
	}
	return NULL;
}

bool ll_isEmpty(LinkedList *ll){
	return (ll->start == NULL);
}

int ll_getLength(LinkedList *ll){
	return ll->len;
}

void ll_debugPrint(LinkedList *ll){
	Node *node = ll->start;
	if(node == NULL){
		return;
	}
	Node *end;
	printf("\n");
	while(node != NULL){
		switch ((*ll).type){
			case 0:
				printf("%i\t",*((int*)node->data));
				break;
			case 1:
				printf("%f\t",*((float*)node->data));
				break;
			case 2:
				printf("%c\t",*((char*) node->data));
				break;
			default:
				printf("error : something is wrong!!");
				break;
		}
		end = node->next;
		node = end;
	}
}
