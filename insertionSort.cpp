#include <iostream>

using namespace std;

int* insertionSort(int* list, int n);

int main(){
	int n;
	int* list;
	cout<<"Please insert n and then insert your list to be sorted: "<<endl;
	cin>>n;
	list=new int[n];

	for(int i=0; i<n; i++){
		cin>>list[i];
	}

	insertSortion(list, n);

	for(int i=0; i<n; i++){
		cout<<list[i]<<" ";
	}

	system("pause");
	return 0;
}

int* insertSortion(int* list, int n){
	int t;

	for(int i=1; i<n; i++){
		//Insertion Step
		for(int j=i; j>0; j--){
			if (list[j]<list[j-1]){
				t=list[j];
				list[j]=list[j-1];
				list[j-1]=t;
			}
		}
	}
	return list;
}