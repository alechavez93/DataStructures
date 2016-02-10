#include "sparseMatrix.cpp"
#include <iostream>

using namespace std;


int main() {

	linkedList<int> *list = new linkedList<int>();
	linkedList<int> *list2 = new linkedList<int>();
	list->add(0, 1);
	list->add(6, 13);


	list2->add(1, 7);
	list2->add(3, 9);
	list2->add(6, 7);
	list2->add(9, -5);

	list->addRow(list2);
	list->printList();
	cout << endl << list->size;
	

	system("pause");
	return 0;
}
