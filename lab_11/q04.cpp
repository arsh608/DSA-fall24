#include <iostream>
#include <vector>
using namespace std;

class BankingSystem {
private:
    vector<int> hashTable;
    int size;

    int primaryHash(int ID) {
        return ID % size;
    }

    int secondaryHash(int ID) {
        return 7 - (ID % 7);
    }

public:
    BankingSystem(int size) : size(size), hashTable(size, -1) {}

    void insert(int ID) {
        int index = primaryHash(ID);
        int step = secondaryHash(ID);

        while (hashTable[index] != -1) {
            index = (index + step) % size; // Double hashing
        }
        hashTable[index] = ID;
    }

    void remove(int ID) {
        int index = primaryHash(ID);
        int step = secondaryHash(ID);

        while (hashTable[index] != -1) {
            if (hashTable[index] == ID) {
                hashTable[index] = -1; // Mark as deleted
                return;
            }
            index = (index + step) % size;
        }
        cout << "Account number " << ID << " not found.\n";
    }

    void search(int ID) {
        int index = primaryHash(ID);
        int step = secondaryHash(ID);

        while (hashTable[index] != -1) {
            if (hashTable[index] == ID) {
                cout << "Account number " << ID << " found.\n";
                return;
            }
            index = (index + step) % size;
        }
        cout << "Account number " << ID << " not found.\n";
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
    BankingSystem bank(11);

    bank.insert(101);
    bank.insert(111);
    bank.insert(121);
    bank.insert(131);
    bank.insert(141);
    bank.insert(151);

    cout << "Initial Hash Table:\n";
    bank.display();

    bank.search(111);
    bank.search(141);
    bank.search(161);

    bank.remove(111);
    bank.remove(131);
    bank.insert(161);
    bank.insert(171);

    cout << "\nHash Table After Operations:\n";
    bank.display();

    return 0;
}
