#include<iostream>


using namespace std;
//Struct for node
template<class T>
struct node{
	T value;
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
	int size;

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


//Functions
template<class T>
linkedList<T>::linkedList(){
	temp = NULL;
	first = NULL;
	last = NULL;
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
	//Work with temp
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
	if(list->size * step > size)
	return;
	
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
		size++;
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


int main() {

	int n, m, s, k, element;
	linkedList<int> *list2 = new linkedList<int>();
	linkedList<int> *list = new linkedList<int>();

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> element;
		list->add(element);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> element;
			list2->add(element);
		}
		list->merge(s, list2);
		list2->eraseList();
	}

	list->printList();
	return 0;
}
