#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};

class stacks {
    private:
    node* top;

    public:
    stacks() {
        top = NULL;
    }
    node* createnewnode(int value){
    node* new_node = new(node);
    if(new_node == NULL){
        return NULL;
    }
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
    }
    
    bool isEmpty(){
        return top == NULL;
    }

    void push(int value){
        node* new_node = createnewnode(value);
        new_node->next = top;
        top = new_node;
    }

    void pop(){
        if(isEmpty()){
            cout<< "Underflow";
        }
        node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            cout<< "Empty";
        }
        cout<< top->data << endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"NULL";
        }
        node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};
int main(){
    stacks s1;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int k;
        cin >> k;
        s1.push(k);
    }
    s1.display();
    cout << endl;
    s1.pop();
    s1.peek();
}