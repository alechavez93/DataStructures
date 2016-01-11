#include "arrayList.cpp"
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
	myList->add(15);
	myList->add(15);
	myList->add(15);
	myList->add(15);
	myList->display();
	myList->addElementAt(7, 1);
	cout << endl;
	myList->display();
	cout << endl;
	myList->eraseAt(2);
	myList->display();
	cout << endl;
	cout << myList->currSize << " " << myList->totalSize << " ";

	//system("pause");
	return 0;
}