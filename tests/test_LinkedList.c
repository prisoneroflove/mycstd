#include "../src/LinkedList.c"
#include "utils.c"
#include<stdio.h>

//Test struct to emulate a user-defined datatype
typedef struct Player{
	int health;
}Player;


int main(){
	//basic datatypes- Should work

	//User defined - idk probably will
	
	//llInt
	LinkedList llInt = ll_new(sizeof(int));
	printf("\nLL_INT\n");
	int x,y,z;
	x = 2;
	y = 4;
	z = 3;
	ll_addNode(&llInt,&x);
	ll_addNode(&llInt,&y);
	ll_addNode(&llInt,&z);
	Node* node_int_back = ll_getPtrBack(&llInt);
	Node* just_before_back = ll_getNodeBefore(&llInt,node_int_back);
	ll_removeLast(&llInt);
	//NOTE: node_int_back is dangling now
	assert(ll_getPtrBack(&llInt) == just_before_back, "ll_remove back, ll_getNodeBefore\n");

	ll_removeFirst(&llInt);
	assert(llInt.start == ll_getPtrFront(&llInt), "ll_removeFirst\n");

	ll_pushFront(&llInt,&x);
	assert(*(int*)ll_getPtrFront(&llInt)->data == x, "ll_pushFront, ll_getPtrFront\n");

	assert(ll_getPtrContainsOrNull(&llInt,&y) == ll_advance(ll_getPtrFront(&llInt)),"ll_getPtrContainsOrNull, ll_advance");

	assert(ll_getLength(&llInt) == 2, "ll_getLength");

	assert(!ll_isEmpty(&llInt), "ll_isEmpty");
	
	//LLFLOAT
	LinkedList llFloat = ll_new(sizeof(float));
	printf("\nllFLoat\n");
	float a,b,c;
	a = 2.3;
	b = 4.1;
	c = 3.0;
	ll_addNode(&llFloat,&a);
	ll_addNode(&llFloat,&b);
	ll_addNode(&llFloat,&c);
	Node* node_back_float = ll_getPtrBack(&llFloat);
	Node* just_before_back_float = ll_getNodeBefore(&llFloat,node_back_float);
	ll_removeLast(&llFloat);
	//NOTE: node_int_back is dangling now
	assert(ll_getPtrBack(&llFloat) == just_before_back_float, "ll_remove back, ll_getNodeBefore\n");

	ll_removeFirst(&llFloat);
	assert(llFloat.start == ll_getPtrFront(&llFloat), "ll_removeFirst\n");

	ll_pushFront(&llFloat,&a);
	assert(*(float*)ll_getPtrFront(&llFloat)->data == a, "ll_pushFront, ll_getPtrFront\n");

	assert(ll_getPtrContainsOrNull(&llFloat,&b) == ll_advance(ll_getPtrFront(&llFloat)),"ll_getPtrContainsOrNull, ll_advance");

	assert(ll_getLength(&llFloat) == 2, "ll_getLength");

	assert(!ll_isEmpty(&llFloat), "ll_isEmpty");

	LinkedList llChar = ll_new(sizeof(char));
	printf("\nLL_CHAR\n");
	char d,e,f;
	d = 'a';
	e = 'b';
	f = '5';
	ll_addNode(&llChar,&d);
	ll_addNode(&llChar,&e);
	ll_addNode(&llChar,&f);
	Node* node_back_char = ll_getPtrBack(&llChar);
	Node* just_before_back_char = ll_getNodeBefore(&llChar,node_back_char);
	ll_removeLast(&llChar);
	//NOTE: node_int_back is dangling now
	assert(ll_getPtrBack(&llChar) == just_before_back_char, "ll_remove back, ll_getNodeBefore\n");

	ll_removeFirst(&llChar);
	assert(llChar.start == ll_getPtrFront(&llChar), "ll_removeFirst\n");

	ll_pushFront(&llChar,&d);
	assert(*(char*)ll_getPtrFront(&llChar)->data == d, "ll_pushFront, ll_getPtrFront\n");

	assert(ll_getPtrContainsOrNull(&llChar,&e) == ll_advance(ll_getPtrFront(&llChar)),"ll_getPtrContainsOrNull, ll_advance");

	assert(ll_getLength(&llChar) == 2, "ll_getLength");

	assert(!ll_isEmpty(&llChar), "ll_isEmpty");

	LinkedList llPlayer = ll_new(sizeof(Player));
	printf("\nLL_PLAYER\n");
	Player p1,p2,p3;
	p1.health = 12;
	p2.health = 40;
	p3.health = 33;
	ll_addNode(&llPlayer,&p1);
	ll_addNode(&llPlayer,&p2);
	ll_addNode(&llPlayer,&p3);
	Node* node_back_player = ll_getPtrBack(&llPlayer);
	Node* just_before_back_player = ll_getNodeBefore(&llPlayer,node_back_player);
	ll_removeLast(&llPlayer);
	//NOTE: node_int_back is dangling now
	assert(ll_getPtrBack(&llPlayer) == just_before_back_player, "ll_remove back, ll_getNodeBefore\n");

	ll_removeFirst(&llPlayer);
	assert(llPlayer.start == ll_getPtrFront(&llPlayer), "ll_removeFirst\n");

	ll_pushFront(&llPlayer,&p1);
	assert((*(Player*)ll_getPtrFront(&llPlayer)->data).health == p1.health, "ll_pushFront, ll_getPtrFront\n");

	assert(ll_getPtrContainsOrNull(&llPlayer,&p2) == ll_advance(ll_getPtrFront(&llPlayer)),"ll_getPtrContainsOrNull, ll_advance");

	assert(ll_getLength(&llPlayer) == 2, "ll_getLength");

	assert(!ll_isEmpty(&llPlayer), "ll_isEmpty");


	//Clean and free each list
	ll_cleanList(&llInt);
	ll_cleanList(&llFloat);
	ll_cleanList(&llChar);
	ll_cleanList(&llPlayer);
}
