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
	while (first->next != NULL){
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
	if (index > size - 1){
		cout << "Index out of bounds" << endl;
		return;
	}
	//Loop through the list
	for (int i = 0; i < index; i++){
		temp = temp->next;
	}
	return temp;
}


template<class T>
void linkedList<T>::printList(){
	//Work with temp node
	temp = first;
	//Loop and cout
	while (temp->next != NULL){
		cout << temp->value << " ";
	}
}


template<class T>
void linkedList<T>::insertAt(T *element, int index){

}


template<class T>
void linkedList<T>::interleave(linkedList *list){

}

#endif