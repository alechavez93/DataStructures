#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

//Struct for node
template<class T>
struct node{
	T value;
	T* next;
};


//Class header for linkedList
template<class T>
class linkedList{

//Fields
private:
	node<T> *first = NULL;
	node<T> *temp = NULL;
	int size = 0;

//Functions
public:
	//Constructor
	linkedList();

	//Destructor
	void eraseList();

	//Access element at an index i
	T elementAt(int index);

	//Inserts node at specific index
	void insertAt(T *element, int index);

	//Interleave function, takes one linkedList as input
	void interleave(linkedList *list);

	//Print list
	void printList();

	//Optional
	//-------------------------------------------------------
	void eraseAt(int i);

	
};

#endif