#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++; // Increment index of smaller element
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1; //index of the pivot
}
*/

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int leftPointer = low + 1;
    int rightPointer = high;

    while (true) {
        while (leftPointer <= high && arr[leftPointer] < pivot) {
            leftPointer++;
        }
        while (rightPointer > low && arr[rightPointer] > pivot) {
            rightPointer--;
        }
        
        if (leftPointer >= rightPointer) {
            break;
        } else {
            swap(arr[leftPointer], arr[rightPointer]);
        }
    }
    swap(arr[low], arr[rightPointer]); //pivot swap
    return rightPointer; //index of the pivot
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    quicksort(arr, 0, size - 1);
    display(arr,  size);
    return 0;
}
