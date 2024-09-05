#include <iostream>

const int SIZE = 5;

using namespace std;

const bool friendships[SIZE][SIZE] = {
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {1, 1, 0, 1, 0}
};

bool find_common_friends(int person1, int person2) {
    bool found = false;
    for (int k = 0; k < SIZE; ++k) {
        if (friendships[person1][k] && friendships[person2][k]) {
            cout << k << " ";
            found = true;
        }
    }
    return found;
}

int main() {
    int person1, person2;
    cout << "Enter the first person number: ";
    cin >> person1;
    cout << "Enter the second person number: ";
    cin >> person2;

    cout << "Common friends: ";
    if (!find_common_friends(person1, person2))
        cout << "None" << endl;

    return 0;
}
