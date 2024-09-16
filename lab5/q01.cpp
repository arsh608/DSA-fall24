#include<iostream>
using namespace std;

void recursive_sort_array(int arr[], int n){
	if (n==1){
		return;
	}
	
	for (int i=0; i < n-1 ; i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i], arr[i+1]);
		}
	}
	recursive_sort_array(arr,n-1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    recursive_sort_array(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
