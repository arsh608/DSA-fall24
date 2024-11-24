#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Book {
    int bookID;
    string title;
};

class LibraryCatalog {
private:
    vector<list<Book>> hashTable;
    int size;

    int hashFunction(int bookID) {
        return (bookID / 10) % size; // Using author ID to index
    }

public:
    LibraryCatalog(int size) : size(size) {
        hashTable.resize(size);
    }

    void insert(int bookID, string title) {
        int index = hashFunction(bookID);
        hashTable[index].push_back({bookID, title});
    }

    void remove(int bookID) {
        int index = hashFunction(bookID);
        for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
            if (it->bookID == bookID) {
                hashTable[index].erase(it);
                return;
            }
        }
        cout << "Book ID " << bookID << " not found.\n";
    }

    void search(int bookID) {
        int index = hashFunction(bookID);
        for (const auto &book : hashTable[index]) {
            if (book.bookID == bookID) {
                cout << "Book Found: " << bookID << " - " << book.title << "\n";
                return;
            }
        }
        cout << "Book ID " << bookID << " not found.\n";
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            for (const auto &book : hashTable[i]) {
                cout << "[" << book.bookID << " - " << book.title << "] ";
            }
            cout << "\n";
        }
    }
};

int main() {
    LibraryCatalog catalog(10);

    catalog.insert(101, "Book A1");
    catalog.insert(102, "Book A2");
    catalog.insert(103, "Book A3");
    catalog.insert(201, "Book B1");
    catalog.insert(202, "Book B2");
    catalog.insert(301, "Book C1");
    catalog.insert(302, "Book C2");
    catalog.insert(303, "Book C3");
    catalog.insert(304, "Book C4");

    cout << "Initial Hash Table:\n";
    catalog.display();

    catalog.search(101);
    catalog.search(304);
    catalog.search(999); // Non-existent

    catalog.remove(101);
    catalog.remove(304);

    cout << "\nHash Table After Deletions:\n";
    catalog.display();

    return 0;
}
