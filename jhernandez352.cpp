#include<iostream>
#include<vector>
using namespace std;
//Count_Sort 0(n)
void countSort(vector<int> data[], int size, int dec){
	//We need to use this to copy over sorted elements.
	vector<int> * C = new vector<int>[size];;
	//Counts the decimal places.
	int *count = new int[10];
	//Initialize C.
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	//setting up C
	for (int i = 0; i < size; i++)
		count[data[i][dec]]++;
	//C[i] now contains the number of elements equal to i.
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	//C[i] now contains the number of elements equal to i.
	for (int i = size - 1; i >= 0; i--){
		C[count[data[i][dec]] - 1] = data[i];
		count[data[i][dec]]--;
	}
	//copy C to vector.
	for (int i = 0; i < size; i++)
		data[i] = C[i];
	delete[] count;
	delete[] C;
}
//Radix_Sort Function
void radixSort(vector<int> data[], int size){

	for(int i = 9; i >= 0 ; i--)
		countSort(data, size, i);
}
void copyElments(vector<int> data[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 10; j++){
			int element;
			cin >> element;
			data[i].push_back(element);
		}
	}
}
//simple print fuction
void print(vector<int> data[], int size){
	for (int i = 0; i < size; i++){
		//create a pointer to the begining of each vector row of data.
		vector<int>::iterator p = data[i].begin();
		for(int i = 0; i < data[i].size(); i++)
		{
			cout << *p << ";";
			p++;
		}
		cout << endl;
	}	
}
int main(){
	int size;
	cin >> size;
  
	vector<int> *data = new vector<int>[size];
	//add elements to vector.
	copyElments(data,size);
	radixSort(data, size);
	//print
	print(data, size);
	delete [] data;
	return 0;
}
	
	
