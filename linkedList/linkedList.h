#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

//Struct for node
template<class T>
struct node{
	T value = 0;
	node<T>* next = NULL;
};


//Class header for linkedList
template<class T>
class linkedList{

//Fields
public:
	node<T> *first = NULL;
	node<T> *temp = NULL;
	node<T> *last = NULL;
	int size = 0;
	bool merging = false;

//Functions
public:
	//Constructor
	linkedList();

	//Destructor
	void eraseList();

	//Getters


	//Access element at an index i
	T elementAt(int index);

	//Inserts node at specific index
	void insertAt(T element, int index);

	//Interleave function, takes one linkedList as input
	void interleave(int step, linkedList *list);

	void merge(int step, linkedList *list);

	//Print list
	void printList();

	//Add node at the end
	void add(T element);

	//Optional
	//-------------------------------------------------------
	//void eraseAt(int i);

	
};

#endif