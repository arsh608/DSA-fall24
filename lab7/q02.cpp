#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int finishTime;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].finishTime <= R[j].finishTime) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {// Copy elements of L[]
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { // Copy elements of R[]
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void displayTop5(Runner arr[], int size) {
    cout << "Top 5 Fastest Runners:" << endl;
    for (int i = 0; i < 5 && i < size; i++) {
        cout << i + 1 << ". " << arr[i].name 
             << " - " << arr[i].finishTime << " seconds" << endl;
    }
}

int main() {
    const int numRunners = 10;
    Runner runners[numRunners];

    cout << "Enter the names and finish times (in seconds) of 10 participants:" << endl;
    for (int i = 0; i < numRunners; i++) {
        cout << "Runner " << i + 1 << " Name: ";
        cin >> runners[i].name;
        cout << "Finish Time (seconds): ";
        cin >> runners[i].finishTime;
    }

    mergeSort(runners, 0, numRunners - 1);
    displayTop5(runners, numRunners);

    return 0;
}
