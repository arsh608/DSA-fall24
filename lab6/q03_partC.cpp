#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class TicketQueueLL {
private:
    Node* front;
    Node* rear;

public:
    TicketQueueLL() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int passengerID) {
        Node* newNode = new Node(passengerID);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Passenger " << passengerID << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }
        Node* temp = front;
        cout << "Passenger " << front->data << " removed from the queue." << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = front;
            cout << "Current queue: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueueLL tq;
    for (int i = 1; i <= 10; i++) {
        tq.enqueue(i);
    }

    tq.display();
    for (int i = 0; i < 5; i++) {
        tq.dequeue();
    }

    tq.display();
    for (int i = 11; i <= 15; i++) {
        tq.enqueue(i);
    }
    tq.display();

    return 0;
}
