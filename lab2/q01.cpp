#include <iostream>
using namespace std;

int main() {
    int** jaggedArray;
    int rows = 5;

    jaggedArray = new int*[rows];
 
    for (int i = 0; i < rows; i++) {
        jaggedArray[i] = new int[5];
    }
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[10];

        for (int j = 0; j < 5; j++) {
            newRow[j] = jaggedArray[i][j];
        }

        for (int j = 5; j < 10; j++) {
            newRow[j] = 0; 
        }
        delete[] jaggedArray[i];
        jaggedArray[i] = newRow;
    }

cout << "Resized Jagged Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 10; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;
    return 0;
}
