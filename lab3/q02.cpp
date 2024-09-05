//Write a function to reverse the singly linked list.
    void reverseList() {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;      
        current = next;
    }
    head = prev; 
    }
