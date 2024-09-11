#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node* next;
    Node* prev;
public:
    Node(int val, Node* nxt = nullptr, Node* prv = nullptr) : value(val), next(nxt), prev(prv) {}

    friend class DoublyLinkedList;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    Node* find_minimum(Node* start) {
        Node* min_node = start;
        Node* current = start->next;
        while (current) {
            if (current->value < min_node->value)
                min_node = current;
            current = current->next;
        }
        return min_node;
    }
public:
    DoublyLinkedList(Node* head_node = nullptr, Node* tail_node = nullptr) : head(head_node), tail(tail_node) {}

    void sort_list() {
        if (!head || !head->next) return;

        Node* last_sorted = nullptr;
        Node* current = head;

        while (current) {
            Node* min_node = find_minimum(current);

            if (min_node == current) {
                last_sorted = current;
                current = current->next;
                continue;
            }

            if (min_node == tail)
                tail = min_node->prev;
            if (min_node->prev)
                min_node->prev->next = min_node->next;
            if (min_node->next)
                min_node->next->prev = min_node->prev;

            min_node->next = current;
            min_node->prev = last_sorted;
            if (last_sorted)
                last_sorted->next = min_node;
            else {
                head = min_node;
                last_sorted = min_node;
            }
            current->prev = min_node;
            last_sorted = min_node;
        }

        current = head;
        while (current && current->next) {
            if (current->value == current->next->value) {
                Node* duplicate = current->next;
                if (duplicate == tail)
                    tail = current;
                current->next = duplicate->next;
                if (current->next)
                    current->next->prev = current;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }

    void insert_front(int val) {
        Node* new_node = new Node(val);
        if (!head) {
            head = tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insert_end(int val) {
        Node* new_node = new Node(val);
        if (!head) {
            head = tail = new_node;
            return;
        }
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    void insert_after(int val, int after_val) {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->value == after_val)
                break;
            current = current->next;
        }

        if (!current) {
            cout << "Value not found in the list" << endl;
            return;
        }

        Node* new_node = new Node(val);
        new_node->prev = current;
        new_node->next = current->next;

        if (current->next)
            current->next->prev = new_node;
        current->next = new_node;
        if (current == tail)
            tail = new_node;
    }

    void insert_before(int val, int before_val) {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->value == before_val)
                break;
            current = current->next;
        }

        if (!current) {
            cout << "Value not found in the list" << endl;
            return;
        }

        Node* new_node = new Node(val);
        new_node->next = current;
        new_node->prev = current->prev;

        if (current->prev)
            current->prev->next = new_node;
        current->prev = new_node;
        if (current == head)
            head = new_node;
    }

    void delete_front() {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void delete_end() {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void delete_value(int val) {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->value == val)
                break;
            current = current->next;
        }

        if (!current) {
            cout << "Value not found in the list" << endl;
            return;
        }

        Node* temp = current;

        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete temp;
    }

    void print_forward() {
        Node* current = head;
        while (current) {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "end" << endl;
    }

    void print_reverse() {
        Node* current = tail;
        while (current) {
            cout << current->value << " -> ";
            current = current->prev;
        }
        cout << "end" << endl;
    }
};

void task_4_tests() {
    DoublyLinkedList l;
    l.insert_front(0);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.insert_before(2, 0);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.insert_before(1, 0);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.insert_before(3, 2);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.delete_value(0);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.delete_value(3);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.delete_value(2);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.delete_value(1);
    l.print_forward();
    l.print_reverse();
    cout << endl;
}

void task_5_tests() {

}

int main() {
    DoublyLinkedList l;
    l.insert_front(2);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(4);
    l.insert_front(1);
    l.insert_front(3);
    l.insert_front(1);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(1);
    l.insert_front(4);
    l.insert_front(3);
    l.print_forward();
    l.print_reverse();
    cout << endl;
    l.sort_list();
    l.print_forward();
    l.print_reverse();

    return 0;
}
