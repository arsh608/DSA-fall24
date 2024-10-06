#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return;
            }
            // Move all elements s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        //top of s2 = front of queue
        cout << "Dequeued: " << s2.top() << endl;
        s2.pop();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    void display() {
        if (s2.empty() && s1.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        stack<int> tempS1 = s1, tempS2 = s2;
        cout << "Queue from front to rear: ";

        // Display elements of s2 (if any) as they are in front of queue
        while (!tempS2.empty()) {
            cout << tempS2.top() << " ";
            tempS2.pop();
        }

        // Display elements of s1 in reverse order
        stack<int> tempS1Reversed;
        while (!tempS1.empty()) {
            tempS1Reversed.push(tempS1.top());
            tempS1.pop();
        }
        while (!tempS1Reversed.empty()) {
            cout << tempS1Reversed.top() << " ";
            tempS1Reversed.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}
