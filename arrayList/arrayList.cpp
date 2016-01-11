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
	//Loops until it finds first element desired and returns its index
	for (int i = 0; i < currSize; i++){
		if (list[i] == element)
			return i;
	}
	//Returns index -1 if nothing found
	return -1;
}

template <class T>
void arrayList<T>::add(T element){
	//If we have space we just add it at the end
	if (currSize < totalSize){
		list[currSize] = element;
		currSize++;
	}
	//If we dont have space we increase the total size and then we insert the element
	else{
		increaseTotalSize(2);
		list[currSize] = element;
		currSize++;
	}
}

template <class T>
void arrayList<T>::increaseTotalSize(int factor){
	//Creates a new array of type T with the new size
	int newSize = (int)(factor*totalSize);
	T* newList = new T[newSize];

	//Copy elements of current array
	for (int i = 0; i < currSize; i++){
		newList[i] = list[i];
	}

	//Deletes old array
	eraseList();

	//Copies pointer value to the old array and ready to use!
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


#endif