#ifndef SPARCEMATRIX_CPP
#define SPARCEMATRIX_CPP

#include <iostream>


//LINKED LIST CLASS 
//---------------------------------------------------------------------------------------------------------------------------
//Struct for node
template<class T>
struct node {
	int index;
	T value;
	node<T>* next = NULL;
};


//Class header for linkedList
template<class T>
class linkedList {

	//Fields
public:
	node<T> *first = NULL;
	node<T> *prev = NULL;
	node<T> *temp = NULL;
	node<T> *last = NULL;
	int size;

	//Functions
public:
	//Constructor
	linkedList();

	//Destructor
	void eraseList();

	//Access element at an index i
	T elementAt(int index);

	//Print list
	void printList();

	//Add node at the end
	void add(int index, T element);

	//Add row (merges the upcoming list into ours acording to indexes)
	void addRow(linkedList *list);
};




//SPARSE MATRIX CLASS
//----------------------------------------------------------------------------------------------------------------------------
template<class T>
class sparceMatrix {

//Fields
public:
	int size;
	linkedList<T> **rows;
	
	
//Functions
public:
	sparceMatrix(int size);
	void addMatrix(sparceMatrix *matrix);
	void searchValues(T values);
};




//Functions for sparse matrix
//----------------------------------------------------------------------------------------------------------------------------
template<class T>
sparceMatrix<T>::sparceMatrix(int size) {
	this->size = size;
	rows = new linkedList<T> *[size];

	for (int i = 0; i < size; i++)
		rows[i] = new linkedList<T>();
}


template<class T>
void sparceMatrix<T>::addMatrix(sparceMatrix *matrix) {

	for (int i = 0; i < size; i++) {
		rows[i]->addRow(matrix->rows[i]);
	}

}


template<class T>
void sparceMatrix<T>::searchValues(T value) {
	node<T> *temp;

	for (int i = 0; i < size; i++) {
		temp = rows[i]->first->next;
		while (temp != NULL) {
			if (temp->value == value) {
				cout << i << " " << temp->index << " ";
			}
			temp = temp->next;
		}
	}
	cout << endl;
}




//Functions for linkedlist
//--------------------------------------------------------------------------------------------------------------------------
template<class T>
linkedList<T>::linkedList() {
	first = new node<T>();
	last = first;
	prev = NULL;
	temp = NULL;
	size = 0;
}


template<class T>
void linkedList<T>::eraseList() {
	//Reset size
	size = 0;

	//Loop thought the list and delete nodes
	while (first->next != NULL) {
		temp = first->next;
		delete first;
		first = temp;
	}
	delete first;
}


template<class T>
T linkedList<T>::elementAt(int index) {
	//Work with temp node
	temp = first->next;

	//Check for bad index
	if (index > size - 1) {
		cout << "Index out of bounds" << endl;
		return first->value;
	}
	
	//Need to match the index of the node
	while (temp != NULL && index != temp->index) {
		temp = temp->next;
	}
	
	return temp->value;
}


template<class T>
void linkedList<T>::printList() {
	//Work with temp node
	temp = first->next;

	//Loop and cout
	while (temp != NULL) {
		cout << temp->index << "-" << temp->value << "  ";
		temp = temp->next;
	}
}


template<class T>
void linkedList<T>::add(int index, T element) {

	node<T> *newNode = new node<T>();
	newNode->index = index;
	newNode->value = element;
	newNode->next = NULL;
	last->next = newNode;
	last = newNode;
	size++;
}


template<class T>
void linkedList<T>::addRow(linkedList *list) {
	node<T> *newNode, *temp2;
	prev = first;
	temp = first->next;
	temp2 = list->first->next;

	while (temp2 != NULL && temp != NULL) {

		newNode = new node<T>();
		newNode->index = temp2->index;
		newNode->value = temp2->value;

		if (newNode->index < temp->index) {

			//We insert the new node before temp
			newNode->next = temp;
			prev->next = newNode;
			prev = newNode;
			size++;

			//Jump to next adding node after insertion
			temp2 = temp2->next;
		}
		else if (newNode->index == temp->index) {

			//Newnode is in the same index as temp
			temp->value += newNode->value;
			delete newNode;
			prev = temp;
			temp = temp->next;

			//Jump to next adding node after insertion
			temp2 = temp2->next;
		}
		else {

			//Newnode goes after index
			prev = temp;
			temp = temp->next;
		}

		
	}

	last = prev;	//The last node becomes prev since temp = NULL

	//If the second chain still has nodes we attach them at the end
	while (temp2 != NULL) {

		//Create a new node and copy temp2's value
		newNode = new node<T>();
		newNode->index = temp2->index;
		newNode->value = temp2->value;

		//Attach it at the end
		last->next = newNode;
		last = newNode;
		
		//Next node and increase size
		temp2 = temp2->next;
		size++;
	}
}


#endif