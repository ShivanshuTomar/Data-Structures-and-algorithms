#include <bits/stdc++.h>
using namespace std;
// ************ circular linked list*********

struct node{
    int data;
    struct node* next;
};

node* head = NULL;
node* last = NULL;

// function to create a node
node* createnode(int value){
    node* newnode = new(node);
    if(newnode == NULL){
        return NULL;
    }else{
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

//function to add at end

void insert_end(int value) {
    node* insert_node = createnode(value);
    if (head == NULL) {
        head = insert_node;
        head->next = head; // Circular link
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = insert_node;
        insert_node->next = head; // Circular link
        last = insert_node;
    }
}
void insert_beginning(int value) {
    node* insert_node = createnode(value);
    if (head == NULL) {
        head = insert_node;
        head->next = head; // Circular link
        last = head;
    } else {
        insert_node->next = last->next; // Link new node to the current second node
        last->next = insert_node; // Update head's next to the new node
        head = insert_node;
    }
}

void delete_beginning(){
    node* temp = last->next;
    temp = temp->next;
    last->next = temp;
    head = temp;
}

void delete_last(){
    node* temp = head;
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = head;
    free(last);
    last = temp;
}


void traversal() {
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void reverse() {
    node* current = last->next;
    node* previous = last;
    node* nextNode;
    
    do {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    } while (current != last);
    
    head = last;  // Update head to point to the new first node
    last->next = previous;  // Update next pointer of the last node to point to the new first node
}





int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n ;i++){
        int k;
        cin >> k;
        insert_beginning(k);
    }
    //delete_beginning();
    // delete_last();
    // traversal();
    // cout << head->data;
    // cout << "\n";
    // cout << last->data;
    reverse();
     traversal();
    

    return 0;
}