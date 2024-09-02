#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int val) : data(val), next(NULL) {}
};

class linkedlist {
public:
    node* head;
    
    linkedlist() : head(NULL) {}
    
    void insertattail(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        node* currentptr = head;
        while (currentptr->next != NULL) {
            currentptr = currentptr->next;
        }
        currentptr->next = newNode;
    }
    
    void insertatfront(int val) {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertaftervalue(int value, int insertingvalue) {
        node* currentptr = head;
        while (currentptr != NULL && currentptr->data != value) {
            currentptr = currentptr->next;
        }
        if (currentptr != NULL) {
            node* newNode = new node(insertingvalue);
            newNode->next = currentptr->next;
            currentptr->next = newNode;
        } else {
            cout << "There is NO node with the given value" << endl;
        }
    }

    void insertbeforevalue(int value, int insertingvalue) {
        if (head == NULL) return;
        
        if (head->data == value) {
            insertatfront(insertingvalue);
            return;
        }
        
        node* currentptr = head;
        while (currentptr->next != NULL && currentptr->next->data != value) {
            currentptr = currentptr->next;
        }
        
        if (currentptr->next != NULL) {
            node* newNode = new node(insertingvalue);
            newNode->next = currentptr->next;
            currentptr->next = newNode;
        } else {
            cout << "There is NO node with the given value" << endl;
        }
    }

    void deletefromhead() {
        if (head == NULL) return;
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deletelastnode() {
        if (head == NULL) return;
        
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        
        node* currentptr = head;
        while (currentptr->next->next != NULL) {
            currentptr = currentptr->next;
        }
        
        delete currentptr->next;
        currentptr->next = NULL;
    }

    void deletebynodevalue(int value) {
        if (head == NULL) return;
        
        if (head->data == value) {
            deletefromhead();
            return;
        }
        
        node* currentptr = head;
        while (currentptr->next != NULL && currentptr->next->data != value) {
            currentptr = currentptr->next;
        }
        
        if (currentptr->next != NULL) {
            node* temp = currentptr->next;
            currentptr->next = currentptr->next->next;
            delete temp;
        } else {
            cout << "There is NO node with the given value" << endl;
        }
    }

    int countnodes() {
        int count = 0;
        node* currentptr = head;
        while (currentptr != NULL) {
            count++;
            currentptr = currentptr->next;
        }
        return count;
    }

    void display() {
        node* currentptr = head;
        while (currentptr != NULL) {
            cout << currentptr->data << "->";
            currentptr = currentptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linkedlist list;
    
    list.insertattail(10);
    list.insertattail(20);
    list.insertattail(30);
    
    cout << "Initial list: ";
    list.display();
    
    list.insertatfront(5);
    cout << "After inserting at front: ";
    list.display();
    
    list.insertaftervalue(20, 25);
    cout << "After inserting 25 after 20: ";
    list.display();
    
    list.insertbeforevalue(30, 28);
    cout << "After inserting 28 before 30: ";
    list.display();
    
    list.deletebynodevalue(25);
    cout << "After deleting node with value 25: ";
    list.display();
    
    list.deletelastnode();
    cout << "After deleting last node: ";
    list.display();
    
    cout << "Number of nodes: " << list.countnodes() << endl;
    
    return 0;
}
