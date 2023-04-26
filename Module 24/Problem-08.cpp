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

void deleteNode(Node *&head, int n, int m){
    Node *temp = head;

    while(temp->Next != NULL){
        int count1 = 0;
        int count2 = 0;

        while(temp->Next != NULL && count1 < n-1){
            temp = temp->Next;
            count1++;
        }
        while(temp->Next != NULL && count2 < m){
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
            count2++;
        }
        if(temp->Next != NULL){
            temp = temp->Next;
        }
    }
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
    int k,n,m;
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        int value;
        cin>>value;
        insertAtTail(head,value);
    }
    deleteNode(head,n,m);

    display(head);

    return 0;
}