#include <iostream>
#include <vector>
using namespace std;

class FitnessClub {
private:
    vector<int> hashTable;
    int size;

    int hashFunction(int ID) {
        return ID % size;
    }

public:
    FitnessClub(int size) : size(size), hashTable(size, -1) {}

    void insert(int ID) {
        int index = hashFunction(ID);
        while (hashTable[index] != -1) {
            index = (index + 1) % size; // Linear probing
        }
        hashTable[index] = ID;
    }

    void remove(int ID) {
        int index = hashFunction(ID);
        while (hashTable[index] != -1) {
            if (hashTable[index] == ID) {
                hashTable[index] = -1; // Mark as deleted
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Member ID " << ID << " not found.\n";
    }

    void search(int ID) {
        int index = hashFunction(ID);
        while (hashTable[index] != -1) {
            if (hashTable[index] == ID) {
                cout << "Member ID " << ID << " found.\n";
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Member ID " << ID << " not found.\n";
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            if (hashTable[i] == -1)
                cout << "[ ] ";
            else
                cout << "[" << hashTable[i] << "] ";
        }
        cout << "\n";
    }
};

int main() {
    FitnessClub club(7);

    club.insert(10);
    club.insert(20);
    club.insert(30);
    club.insert(40);
    club.insert(50);
    club.insert(60);

    cout << "Initial Hash Table:\n";
    club.display();

    club.search(30);
    club.search(50);
    club.search(70); // Non-existent

    club.remove(20);
    club.remove(40);
    club.insert(70);
    club.insert(80);

    cout << "\nHash Table After Operations:\n";
    club.display();

    return 0;
}
