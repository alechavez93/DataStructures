#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "linkedList.h";

//Functions
template<class T>
linkedList<T>::linkedList(){
	temp = NULL;
	first = NULL;
	size = 0;
}


template<class T>
void linkedList<T>::eraseList(){
	//Reset size
	size = 0;

	//Loop thought the list and delete nodes
	while(first->next != NULL){
		temp = first->next;
		delete first;
		first = temp;
	}
	delete first;
}


template<class T>
T linkedList<T>::elementAt(int index){
	//Work with temp node
	temp = first;

	//Check for bad index
	if(index > size - 1){
		cout << "Index out of bounds" << endl;
		return first->value;
	}
	//Loop through the list
	for(int i = 0; i < index; i++){
		temp = temp->next;
	}
	return temp->value;
}


template<class T>
void linkedList<T>::printList(){
	//Work with temp node
	temp = first;

	//Loop and cout
	while (temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
}


template<class T>
void linkedList<T>::insertAt(T element, int index){
	//Work with temp if we are not merging
	temp = first;
	
	//An index greater than size will be a bad index
	if(index > size){
		cout << "Incorrect index (select from 0 to "<< size <<endl;
		return;
	}
	//In case of an empty list
	if(size == 0) {
		first = new node<T>();
		first->value = element;
		first->next = NULL;
		size++;
		return;
	}
	//Create a new Node
	node<T> *newNode = new node<T>();
	newNode->value = element;

	//Insert at position 0
	if(index == 0){
		newNode->next =  first;
		first = newNode;
	}
	else{
		//Get to the node before index
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
			
		//Insert the new node
		newNode->next =  temp->next;
		temp->next = newNode;
	}
	//Increment size
	size++;
}


template<class T>
void linkedList<T>::merge(int step, linkedList *list) {
	//In case of the first step we use step - 1
	int firstStep = step - 1;

	//temp to navigate our big list, temp2 to navigate small list 
	temp = first;
	node<T> *temp2 = list->first;

	//A new node to store the inserted node
	node<T> *newnode;

	while (temp2 != NULL) {

		//Store the new node
		newnode = new node<T>();
		newnode->value = temp2->value;

		//We modify our step once past the first insertion
		if (temp != first)
			firstStep = step;

		//Look fro the right place to insert
		for (int i = 0; i < firstStep; i++) {
				temp = temp->next;
		}

		//insert step (insert the new node)
		newnode->next = temp->next;
		temp->next = newnode;
		temp = newnode;

		//get to the next element
		temp2 = temp2->next;
	}
}


template<class T>
void linkedList<T>::add(T element) {
	//Work with temp
	temp = first;

	//In case of an empty list
	if (size == 0) {
		first = new node<T>();
		first->value = element;
		first->next = NULL;

		//Last node points to the same as first node
		last = first;
		size++;
	}
	else {
		node<T> *newNode = new node<T>();
		newNode->value = element;
		newNode->next = NULL;
		last->next = newNode;
		last = newNode;
		size++;
	}
}

#endif