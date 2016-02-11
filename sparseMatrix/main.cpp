#include "sparseMatrix.cpp"
#include <iostream>

using namespace std;


int main() {

	int rows, numberPerRow, index, value, n, searchValue;

	//Filling the first matrix
	cin >> rows;
	sparceMatrix<int> *A = new sparceMatrix<int>(rows);

	for (int i = 0; i < rows; i++) {
		cin >> numberPerRow;

		for (int j = 0; j < numberPerRow; j++) {
			cin >> index;
			cin >> value;

			A->rows[i]->add(index, value);
		}
	}

	//Filling the second matrix
	cin >> rows;
	sparceMatrix<int> *B = new sparceMatrix<int>(rows);

	for (int i = 0; i < rows; i++) {
		cin >> numberPerRow;

		for (int j = 0; j < numberPerRow; j++) {
			cin >> index;
			cin >> value;

			B->rows[i]->add(index, value);
		}
	}


	//Adding the two matrices in A
	A->addMatrix(B);


	//Getting the search values
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> searchValue;

		//Displaying the search values
		A->searchValues(searchValue);
	}



	system("pause");
	return 0;
}
