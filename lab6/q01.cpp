#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int element) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << element << endl;
            return;
        }
        arr[++top] = element;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << std::endl;
    }

};

void separateStacks(Stack& originalStack, Stack& evenStack, Stack& oddStack) {
    while (!originalStack.isEmpty()) {
        int topElement = originalStack.pop();

        if (topElement % 2 == 0) {
            evenStack.push(topElement);
        } else {
            oddStack.push(topElement);
        }
    }
}

int main() {
    Stack originalStack(5);
    Stack evenStack(5);
    Stack oddStack(5);

    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);
    originalStack.push(4);
    originalStack.push(5);
    
    cout << "Original stack: ";
    originalStack.display();

    separateStacks(originalStack, evenStack, oddStack);

    cout << "Even stack: ";
    evenStack.display();

    cout << "Odd stack: ";
    oddStack.display();

    return 0;
}
