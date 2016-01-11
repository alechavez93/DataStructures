#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "arrayList.h";
#include <string>;

template <class T>
arrayList<T>::arrayList(){
	list = new T(totalSize);
}

template <class T>
arrayList<T>::~arrayList(){
	//not sure about this
	delete list;

	//maybe need to loop around and delete every element
	/*for(int i=0; i<currSize; i++){
		delete list[i];
	}*/	
}

template <class T>
int arrayList<T>::getSize(){
	return currSize;
}

template <class T>
T arrayList<T>::get(int index){
	return list[index];
}

template <class T>
int arrayList<T>::indexOf(T element){
	for (int i = 0; i < currSize; i++){
		if (list[i] == element)
			return i;
	}
	return -1;
}

template <class T>
void arrayList<T>::add(T element){
	if (currSize < totalSize){
		list[currSize] = element;
		currSize++;
	}
	else{
		increaseTotalSize(2);
		list[currSize] = element;
		currSize++;
	}
}

template <class T>
void arrayList<T>::increaseTotalSize(int factor){

}

template <class T>
void arrayList<T>::display(){

	for (int i = 0; i < currSize; i++){
		cout << list[i] << " ";
	}
}


#endif