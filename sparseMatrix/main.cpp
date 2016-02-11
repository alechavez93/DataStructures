#include "sparseMatrix.cpp"
#include <iostream>

using namespace std;


int main() {

	linkedList<int> *list1 = new linkedList<int>();
	linkedList<int> *list2 = new linkedList<int>();

	list1->add(0, 1); list1->add(6, 13);
	list2->add(1, 7); list2->add(3, 9); list2->add(6, 7); list2->add(9, -5);

	sparceMatrix<int> *matrix = new sparceMatrix<int>(2);
	matrix->rows[0] = list1;
	matrix->rows[1] = list2;

	sparceMatrix<int> *matrix2 = new sparceMatrix<int>(2);

	list1 = new linkedList<int>();
	list2 = new linkedList<int>();

	list1->add(1, 4);	list1->add(3, 7);	list1->add(5, 7);
	list2->add(0, 7);	list2->add(4, 10);

	matrix2->rows[0] = list1;
	matrix2->rows[1] = list2;

	matrix->addMatrix(matrix2);

	matrix->rows[0]->printList();
	cout << endl;
	matrix->rows[1]->printList();
	cout << endl;

	int *n = new int[4] {2, 4, 7, 1};
	cout << endl << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		matrix->searchValues(n[i]);
		cout << endl;
	}


	system("pause");
	return 0;
}
