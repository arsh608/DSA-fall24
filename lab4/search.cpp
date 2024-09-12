#include <iostream>

using namespace std;

void print(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linear_search() {
    cout << "Linear search:\nArray >> ";
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    int value = 2;
    print(arr, n);
    cout << "Value >> " << value << endl;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) {
            cout << value << " exists\n" << endl;
            return;
        }
    }

    cout << value << " doesn't exist\n" << endl;
}

void binary_search() {
    cout << "Binary search:\nArray >> ";
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    int value = 5;
    print(arr, n);
    cout << "Value >> " << value << endl;

    int left = 0, right = n-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            cout << value << " exists\n" << endl;
            return;
        } else if (arr[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << value << " doesn't exist\n" << endl;
}

void interpolation_search() {
    cout << "Interpolation search:\nArray >> ";
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    int value = 1;
    print(arr, n);
    cout << "Value >> " << value << endl;

    int left = 0, right = n - 1;
    while (left <= right) {
        if (arr[left] == arr[right]) {
            if (arr[left] == value) {
                cout << value << " exists\n" << endl;
                return;
            }
            break;
        }

        int pos = left + (value - arr[left]) * (right - left) / (arr[right] - arr[left]);
        if (arr[pos] == value) {
            cout << value << " exists\n" << endl;
            return;
        } else if (arr[pos] < value) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    cout << value << " doesn't exist\n" << endl;
}

int main() {
    linear_search();
    binary_search();
    interpolation_search();

    return 0;
}
