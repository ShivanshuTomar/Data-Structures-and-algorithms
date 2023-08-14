#include <bits/stdc++.h>
using namespace std;
// *********************** Linked List ******************//
struct node{
    int data;
    struct node* next;
};

node* head = NULL;

node* createnewnode(int value){
    node* new_node = new(node);
    if(new_node == NULL){
        return NULL;
    }
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
}
// insert at beginning 
void insert_beginning(int value){
    node* newnode = createnewnode(value);

    if(head == NULL){
        head = newnode;
    }
    newnode->next = head;
    head = newnode;
}
// insert at end
void insert_end(int value){
    node* newnode = createnewnode(value);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp-> next;
    }
    temp->next = newnode;
}
// traversal 
void traversal(){
    
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}

// delete at beginning
void delete_beginning(){
    if(head == NULL){
        cout << "Underflow";
    }
    node* temp = head;
    head = head->next;
    free(temp);
}

// delete at end
void delete_end(){
    node* temp = head;
    if(head == NULL){
        cout << "Underflow";
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void reverse(){
    node*previousnode = NULL;
    node*currentnode = head;
    node*nextnode = head;
    while(nextnode != NULL ){
        nextnode = nextnode->next;
        currentnode->next = previousnode;
        previousnode = currentnode;
        currentnode = nextnode;
    }
    head = previousnode;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n;i++){
        int k;
        cin >> k;
        if(i == 0){
            node* Node = createnewnode(k);
            head = Node;
        }else{
           insert_beginning(k);
        }
    }
    // delete_beginning();
    // delete_end();
    // traversal();
    // cout << "\n";
    // reverse();
    traversal();
    return 0;
}
