#include <iostream>
using namespace std;

class CircularTicketQueue {
private:
    int front, rear, size, capacity;
    int queue[10];

public:
    CircularTicketQueue() {
        front = -1;
        rear = -1;
        size = 0;
        capacity = 10;//max size
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int passengerID) {
        if (isFull()) {
            cout << "Queue is full. Cannot add passenger " << passengerID << "." << endl;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % capacity; // Circular increment
            queue[rear] = passengerID;
            size++;
            cout << "Passenger " << passengerID << " added to the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
        } else {
            cout << "Passenger " << queue[front] << " removed from the queue." << endl;
            front = (front + 1) % capacity; // Circular increment
            size--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current queue: ";
            for (int i = 0; i < size; i++) {
                cout << queue[(front + i) % capacity] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CircularTicketQueue tq;

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
