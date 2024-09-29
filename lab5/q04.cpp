#include <iostream>

using namespace std;

int recursive_binary_search(int array[], int size, int target, int left, int right) {
    if (left > right) return -1;  

    int middle = (right + left) / 2; 
    if (array[middle] < target)
        return recursive_binary_search(array, size, target, middle + 1, right); 
    if (array[middle] > target)
        return recursive_binary_search(array, size, target, left, middle - 1); 
    return middle;
}

int main() {
    int numbers[5] = {3, 2, 6, 9, 10};
    int search_value = 3;

    cout << search_value << " is located at index " << recursive_binary_search(numbers, 5, search_value, 0, 5 - 1) << endl;

    return 0;
}
