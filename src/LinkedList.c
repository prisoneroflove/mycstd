#include "LinkedList.h"
#include <stdio.h>
#include <string.h>

LinkedList ll_new(size_t dataSize) {
  LinkedList ll;
  ll.start = NULL;
  ll.end = NULL;
  ll.len = 0;
  ll.dataSize = dataSize;
  return ll;
}

void ll_setNode(Node *node,const void *value, size_t dataSize) {
  memcpy(node->data, value, dataSize); 
  //node->data = (void*) value;
}
void ll_addNode(LinkedList *ll,const void *value) {
  if (ll_isEmpty(ll)) {
    ll->start = calloc(1, sizeof(Node));
    ll->start->data = calloc(1, ll->dataSize);
    if (ll->start != NULL && ll->start->data != NULL) {
      ll->start->next = NULL;
      //printf(" %p", ll->start->data);
      //printf(" %i", *(int*)ll->start->data);
      //printf(" %i",*(int*)value);
      ll_setNode(ll->start, value, ll->dataSize);
      ll->end = ll->start;
      ll->len += 1;
    } else {
      puts("Error on ll_addNode, couldnt malloc for start");
    }
  } else {
    ll->end->next = (Node *)calloc(1, sizeof(Node));
    ll->end->next->data = calloc(1, ll->dataSize);
    if (ll->end->next != NULL && ll->end->next->data != NULL) {
      ll->end = ll->end->next;
      ll->end->next = NULL;
      ll_setNode(ll->end, value, ll->dataSize);
      ll->len += 1;
    } else {
      puts("Error on ll_addNode, couldnt malloc for end");
    }
  }
}

void ll_freeNodes(LinkedList *ll) {
  Node *node = ll->start;
  if(ll_isEmpty(ll)){return;}
  while (node != NULL) {
    Node *next = node->next;
    free(node->data);
    free(node);
    node = next;
  }
}

void ll_cleanList(LinkedList *ll) {
  if (ll_isEmpty(ll)) {
    // List is already empty, nothing to clean
    return;
  }

  ll_freeNodes(ll);
  ll->start = NULL;
  ll->end = NULL;
  ll->len = 0;
}

void ll_pushFront(LinkedList *ll, const void *value) {
  Node *n = calloc(1, sizeof(Node));
  n->data = calloc(1,ll->dataSize);
  if (n != NULL && n->data != NULL){
    ll_setNode(n,value, ll->dataSize);
    n->next = ll->start;
    ll->start = n;
    ll->len += 1;
  } else {
    printf("ERROR: Couldn't allocate memory for ll_pushFront\n");
  }
}

Node *ll_getPtrFront(LinkedList *ll) { return ll->start; }
Node *ll_getPtrBack(LinkedList *ll) { return ll->end; }

/*Returns the pointer to next node, or NULL*/

Node* ll_advance(Node* node){
	return node->next;
}

void ll_removeFirst(LinkedList *ll) {
  if (!ll_isEmpty(ll)) {
    Node *node = ll->start;
    ll->start = ll->start->next;
    ll->len -= 1;
    free(node->data);
    free(node);
  } else {
    puts("ERROR: NO NODES TO PUT OUT first");
  }
}

void ll_removeLast(LinkedList *ll) {
  if (ll->end != NULL) {
    Node *node = ll_getNodeBefore(ll, ll->end);
    free(ll->end->data);
    free(ll->end);
    ll->end = node;
    ll->end->next = NULL;
    ll->len -= 1;
  } else {
    puts("ERROR: NO NODE TO PUT OUT last");
  }
}

Node *ll_getNodeBefore(LinkedList *ll, Node *node) {
  Node *nod = ll->start;
  while (nod != NULL) {
    if (nod->next == node) {
      return nod;
    }
    nod = nod->next;
  }
  return NULL;
}

Node *ll_getPtrContainsOrNull(LinkedList *ll,const void *value) {
  Node *node = ll->start;
  while (node != NULL) {
    if (memcmp(node->data, value, ll->dataSize) == 0) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

bool ll_isEmpty(LinkedList *ll) { return (ll->start == NULL); }

int ll_getLength(LinkedList *ll) { return ll->len; }

void ll_debugPrint(LinkedList *ll, LL_DEBUG_TYPE debugFormat) {
  Node *node = ll->start;
  if (ll_isEmpty(ll)) {
    return;
  }
  Node *end;
  printf("\n");
  while (node != NULL) {
    switch (debugFormat) {
    case DEBUG_INT:
      printf("%i\t", *((int *)node->data));
      break;
    case DEBUG_FLOAT:
      printf("%f\t", *((float *)node->data));
      break;
    case DEBUG_CHAR:
      printf("%c\t", *((char *)node->data));
      break;
    case DEBUG_HEX:
      printf("%x\t", *((char *)node->data));
    default:
      printf("error : something is wrong!!");
      break;
    }
    end = node->next;
    node = end;
  }
  putchar('\n');
}
