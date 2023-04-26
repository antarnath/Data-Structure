#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    Node(int value){
        this->value = value;
        this->Next = NULL;
    }
};

void insertAtTail(Node *&head, int value){
    Node *newNode = new Node(value);
    
    if(head == NULL){
        head = newNode;;
        return;
    }

    Node *temp = head;

    while(temp->Next != NULL){
        temp = temp->Next;
    }

    temp->Next = newNode;
}

Node *reverseKNodes(Node *head, int k) 
{ 
    Node* current = head; 
    Node* next; 
    Node* prev = NULL; 
    int count = 0; 
  
    while (current != NULL && count < k) 
    { 
    next = current->Next; 
    current->Next = prev; 
    prev = current; 
    current = next; 
    count++; 
    } 
    
    if(next != NULL){
        current->Next = reverseKNodes(next,k);
    }

    return prev;
}


void display(Node *&head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->value;
        if(temp->Next != NULL){
            cout<<" -> ";
        }
        temp = temp->Next;
    }
}

int main(){
    Node *head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        insertAtTail(head,value);
    }
    int k;
    cin>>k;
    head = reverseKNodes(head,k);

    display(head);

    return 0;
}