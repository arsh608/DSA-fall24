#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    int temp;
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) break; 
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 12, 3, 2, 7, 9, 13, 18, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, n);
    bubble_sort(arr, n); 
    printArray(arr, n);

    return 0;
}
