#include <iostream>
using namespace std;

class Node {
private:
    int value;      
    Node* next;   

public:
    Node(int value, Node* next = nullptr) : value(value), next(next) {}

    friend class Singly;
};

class Singly {
private:
    Node* head;

public:
    Singly(Node* head = nullptr) : head(head) {}

    void insert_front(int value) {
        Node* new_node = new Node(value, head);
        head = new_node;
    }

    void segregate() {
        if (!head || !head->next) return;
        
        Node* current_node = head; // Start with the head node

        while (current_node && current_node->next) {
            if ((current_node->next->value & 1) == 0) { 
                Node* temp = current_node->next;
                current_node->next = current_node->next->next;
                temp->next = head;
                head = temp;
            } else {
                current_node = current_node->next;
            }
        }
    }

    void print() const {
        for (Node* current = head; current; current = current->next)
            cout << current->value << " -> ";
        cout << "end" << endl;
    }
};

int main() {
    Singly l;

    l.insert_front(2);
    l.insert_front(6);
    l.insert_front(2);
    l.insert_front(4);

    cout << "Original list: ";
    l.print();

    l.segregate();
    cout << "After segregation: ";
    l.print();

    return 0;
}
