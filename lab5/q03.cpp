#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void reverseList(Node*& head) {
    head = reverseListRecursive(head);
}

int main() {
    Node* head = NULL;

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original List: ";
    printList(head);

    reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
