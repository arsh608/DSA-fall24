#include <iostream>
#include <vector>
using namespace std;

class AcademicPortal {
private:
    vector<int> hashTable;
    int size;
    int count;
    double loadFactorThreshold;

    int hashFunction(int ID, int tableSize) {
        return ID % tableSize;
    }

    void resize() {
        int newSize = size * 2;
        vector<int> newTable(newSize, -1);

        for (int ID : hashTable) {
            if (ID != -1) {
                int index = hashFunction(ID, newSize);
                while (newTable[index] != -1) {
                    index = (index + 1) % newSize; // Linear probing
                }
                newTable[index] = ID;
            }
        }

        hashTable = move(newTable);
        size = newSize;
        cout << "Resized hash table to size " << size << ".\n";
    }

public:
    AcademicPortal(int size, double loadFactorThreshold)
        : size(size), count(0), loadFactorThreshold(loadFactorThreshold), hashTable(size, -1) {}

    void insert(int ID) {
        if ((double)(count + 1) / size > loadFactorThreshold) {
            resize();
        }

        int index = hashFunction(ID, size);
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
        }
        hashTable[index] = ID;
        count++;
    }

    void search(int ID) {
        int index = hashFunction(ID, size);
        int start = index; // For loop termination in case of empty table
        while (hashTable[index] != -1) {
            if (hashTable[index] == ID) {
                cout << "Student ID " << ID << " found.\n";
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Student ID " << ID << " not found.\n";
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
    AcademicPortal portal(7, 0.75);

    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    cout << "Initial Hash Table:\n";
    portal.display();

    portal.search(22);
    portal.search(42);
    portal.search(72);

    // Inserting more IDs to exceed the load factor
    portal.insert(72);
    portal.insert(82);

    cout << "\nHash Table After Resizing:\n";
    portal.display();

    return 0;
}
