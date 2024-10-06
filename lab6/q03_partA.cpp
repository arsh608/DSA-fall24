#include <iostream>
using namespace std;

class TicketQueue {
private:
    int front, rear, size;
    int queue[10]; //size 10

public:
    TicketQueue() {
        front = -1;
        rear = -1;
        size = 10; //max size
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int passengerID) {
        if (isFull()) {
            cout << "Queue is full. Cannot add passenger " << passengerID << "." << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            queue[rear] = passengerID;
            cout << "Passenger " << passengerID << " added to the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
        } else {
            cout << "Passenger " << queue[front] << " removed from the queue." << endl;
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueue tq;

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
