#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template<class T>
class arrayList{

private:
	int currSize = 0;
	int totalSize = 5;
	T* list;

public:
	//Constructor
	arrayList();

	//Destructor
	void eraseList();

	//Gets the current filled size of the arrayList
	int getSize();

	//Returns element at index
	T get(int index);

	//Returns the index of the first element encountered
	int indexOf(T element);

	//Adds a new elemnt to the end of the array list
	void add(T element);

	//Add a new elemet to the specified index
	void addAt(T element, int index);

	//Erases an element at a given index
	void erase(int index);

	//Internal function used to increase list size when full
	void increaseTotalSize(int factor);

	//Displays all elements of the list separated by spaces
	void display();
};

#endif