#include <iostream>
#include <string>

using namespace std;

int main() {
    int numberOfRows;
    cout << "Enter the number of rows: ";
    cin >> numberOfRows;

    string **seatArrangement = new string*[numberOfRows];
    int *seatsPerRow = new int[numberOfRows];

    for (int row = 0; row < numberOfRows; ++row) {
        cout << "Row [" << row << "] - Enter the number of seats: ";
        cin >> seatsPerRow[row];
        seatArrangement[row] = new string[seatsPerRow[row]];

        for (int seat = 0; seat < seatsPerRow[row]; ++seat) {
            cout << "Row [" << row << "] Seat [" << seat << "] - Enter attendee's name: ";
            cin >> seatArrangement[row][seat];
        }
    }

    for (int row = 0; row < numberOfRows; ++row) {
        cout << "Row [" << row << "]: ";
        for (int seat = 0; seat < seatsPerRow[row]; ++seat) {
            cout << seatArrangement[row][seat];
            if (seat != seatsPerRow[row] - 1) cout << ", ";
        }
        cout << endl;
    }

    for (int row = 0; row < numberOfRows; ++row) {
        delete[] seatArrangement[row];
    }
    delete[] seatArrangement;
    delete[] seatsPerRow;

    return 0;
}
