#include "arrayList.h"
#include <iostream>

using namespace std;

int main(){

	arrayList<int> *myList = new arrayList<int>();
	myList->add(2);
	myList->add(4);
	myList->add(6);
	myList->add(8);
	myList->add(10);
	myList->add(15);
	myList->display();

	system("pause");
	return 0;
}