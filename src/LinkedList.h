#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/* Nodes for LinkedList
 * has void-pointer to data and one for next Node
 */
typedef struct Node {
  void *data;
  struct Node *next;
} Node;

/*Linked List: Contains pointer first and last nodes, length of list and size of
 * data in Node*/
typedef struct LinkedList {
  struct Node *start;
  struct Node *end;
  int len;
  size_t dataSize;
} LinkedList;

/*Use this for telling the ll_debugPrint function in which manner to print*/
typedef enum LL_DEBUG_TYPE {
  DEBUG_INT,
  DEBUG_FLOAT,
  DEBUG_CHAR,
  // To print stuff that cant be print in other methods, use it rarely
  DEBUG_HEX,
} LL_DEBUG_TYPE;

/*Returns a empty Linked List
 * start and end is set to Null
 * Use correct datasize*/
LinkedList ll_new(size_t dataSize);

/*adds node to LinkedList given,returns a debug messagen.no errors */
void ll_addNode(LinkedList *ll,const void *value);

/*NOT TO BE USED BY USER
 * sets the data of the Node
 * uses memcpy*/
void ll_setNode(Node *node, const void *value, size_t dataSize);

/* Removes the last Node of the given list. Doesnt returns an error but a
 * message is generated*/
void ll_removeLast(LinkedList *ll);

/* Removes the first Node of the given list if not empty. Doesnt returns an
 * error but a message is generated*/
void ll_removeFirst(LinkedList *ll);

/*Use with causion, iterartes over every element, Thus is't efficent*/
Node *ll_getNodeBefore(LinkedList *ll, Node *node);

/*NOT TO BE USED BY THE USER
 * Used to free all the nodes*/
void ll_freeNodes(LinkedList *ll);

/*Cleans the node and set it all to zero and NULL, no errors*/
void ll_cleanList(LinkedList *ll);

/*Adds Node to the front of the List*/
void ll_pushFront(LinkedList *ll, const void *value);

/*Returns pointer of the first Node or NULL*/
Node *ll_getPtrFront(LinkedList *ll);

/*Returns pointer of the Last Node or NULL*/
Node *ll_getPtrBack(LinkedList *ll);


/*Returns pointer to next node or NULL*/
Node *ll_advance(Node* node);

/* Returns pointer to the Node which contains the data specified Or NULL
 * Can break, use it with caution*/
Node *ll_getPtrContainsOrNull(LinkedList *ll, const void *value);

/* Return if or not the list is empty*/
bool ll_isEmpty(LinkedList *ll);

/*Returns length of the list as int*/
int ll_getLength(LinkedList *ll);

/*Prints the value in Node in specified Manner*/
void ll_debugPrint(LinkedList *ll, LL_DEBUG_TYPE debugFormat);
