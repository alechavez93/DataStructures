#include "sparseMatrix.cpp"
#include <iostream>

using namespace std;


int main() {

	linkedList<int> *list = new linkedList<int>();
	list->add(0, 1);
	list->add(6, 13);
	list->add(8, 4);
	list->printList();

	system("pause");
	return 0;
}
