#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "arrayList.h";
#include <string>;

template <class T>
arrayList<T>::arrayList(){
	//Initiate array to a given size
	list = new T[totalSize];
}

template <class T>
void arrayList<T>::eraseList(){
	//Deletes the whole array
	delete[] list;
}

template <class T>
int arrayList<T>::getSize(){
	//Returns value of current used size
	return currSize;
}

template <class T>
T arrayList<T>::get(int index){
	//Returns value at index
	return list[index];
}

template <class T>
int arrayList<T>::indexOf(T element){
	//Finds first element
	for (int i = 0; i < currSize; i++){
		if (list[i] == element)
			return i;
	}
	//Returns index -1 if nothing found
	return -1;
}

template <class T>
void arrayList<T>::add(T element){
	//Enough space
	if (currSize < totalSize){
		list[currSize] = element;
		currSize++;
	}
	//No space
	else{
		increaseTotalSize(2);
		list[currSize] = element;
		currSize++;
	}
}

template <class T>
void arrayList<T>::increaseTotalSize(int factor){
	//Create a new array
	int newSize = (int)(factor*totalSize);
	T* newList = new T[newSize];

	//Copy elements
	for (int i = 0; i < currSize; i++){
		newList[i] = list[i];
	}

	//Delete old array
	eraseList();

	//Copies new to old
	list = newList;
	totalSize = newSize;
	
}

template <class T>
void arrayList<T>::display(){
	//Loops throught the list and displays all values 
	for (int i = 0; i < currSize; i++){
		cout << list[i] << " ";
	}
}

template <class T>
void arrayList<T>::addElementAt(T element, int index){
	//Enough space
	if (currSize < totalSize){
		//Push list right
		for (int i = currSize - 1; i >= index; i--){
			list[i + 1] = list[i];
		}
		//Insert element and update size
		list[index] = element;
		currSize++;
	}
	//No space in array
	else{
		//Increase size
		increaseTotalSize(2);
		//Push
		for (int i = currSize - 1; i >= index; i--){
			list[i + 1] = list[i];
		}
		//Insert
		list[index] = element;
		currSize++;
	}
}

template <class T>
void arrayList<T>::eraseAt(int index){
	//Shift left
	for (int i = index; i < currSize; i++){
		list[i] = list[i + 1];
	}
	//Decrease size
	currSize--;
}


#endif