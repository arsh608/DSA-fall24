#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* getLastNode(Node* head) {
    while (head && head->next) {
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr) 
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        } 
        else {
            if (prev) 
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr) 
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) 
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) 
            tmp = tmp->next;
        tmp->next = nullptr;

        // Recur for the left part
        newHead = quickSortRecur(newHead, tmp);

        // Join the left part with pivot
        tmp = getLastNode(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getLastNode(*headRef));
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(Node** headRef, int newData) {
    Node* newNode = new Node(newData);
    if (!(*headRef)) {
        *headRef = newNode;
        return;
    }
    Node* last = *headRef;
    while (last->next) 
        last = last->next;
    last->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Sample linked list: 10 -> 7 -> 8 -> 9 -> 1 -> 5 -> 3
    append(&head, 10);
    append(&head, 7);
    append(&head, 8);
    append(&head, 9);
    append(&head, 1);
    append(&head, 5);
    append(&head, 3);

    cout << "Linked List before sorting: ";
    printList(head);

    quickSort(&head);

    cout << "Linked List after sorting: ";
    printList(head);

    return 0;
}
