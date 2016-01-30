#include"linkedList.cpp"
#include<iostream>

using namespace std;

int main() {

	int n, m, s, k, element;
	linkedList<int> *list2 = new linkedList<int>();
	linkedList<int> *list = new linkedList<int>();

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> element;
		list->add(element);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> element;
			list2->add(element);
		}
		list->merge(s, list2);
		list2->eraseList();
	}

	list->printList();
	
	system("pause");
	return 0;
}