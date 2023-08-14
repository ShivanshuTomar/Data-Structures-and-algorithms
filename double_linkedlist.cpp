#include <bits/stdc++.h>
using namespace std;

// Doubly linked list node structure
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

node* head = NULL; // Global head pointer for the linked list
node* tail = NULL;

// Function to create a new node
node* createNode(int value) {
    node* newNode = new(node);
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insert_end(int value) {
    // Create a new node with the given value
    node* newnode = createNode(value);
    
    // Check if the linked list is empty (head is NULL)
    if (head == NULL) {
        // If the linked list is empty, make the new node the head
        head = newnode;
    } else {
        // If the linked list is not empty, find the last node (tail)
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        
        // Attach the new node to the next of the current tail
        tail->next = newnode;
        
        // Set the previous pointer of the new node to point to the current tail
        newnode->prev = tail;
    }
}
// function to insert at beginning
void insert_beginning(int k){
    node* newnode = createNode(k);
    if( head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        head -> prev = newnode;
        newnode -> next = head;
        head = newnode;
        newnode -> prev = NULL;
    }

}
// Function to delete node at beginning
void delete_beginning(){
    node* temp = head;
    if(head == NULL){
        cout << "underflow";
    }
    head = temp->next;
    head->prev = NULL;
    free(temp);
}

// function to delete node from end
void delete_end(){
    node* temp;
    if(tail == NULL){
        cout << "underflow";
    }else{
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }
}

// Function to traverse and print the linked list
void traversal() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//Function to reverse doubly linked list
void reverse(){
    node* current;
    node* nextnode;
    if(head == NULL){
        cout << "error";
    }else{
        current = head;
        while(current != NULL){
            nextnode = current->next;
            current->next = current->prev;
            current->prev = nextnode;
            current = nextnode;
        }
    }
    current = head;
    head = tail;
    tail = current;
}

int main() {
    int n;
    cin >> n; // Input number of elements in the linked list
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k; // Input each element
        insert_beginning(k);// Insert element at the end of the linked list
    }
    traversal(); // Print the linked list
    // delete_end();
    cout << "\n";
    // // traversal();
    // reverse();
    // traversal();
    return 0;
}

