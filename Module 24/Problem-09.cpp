#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;
    Node *Prev;

    Node(int value){
        this->value = value;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

void insertAtHead(Node *&head, int value);
void insertAtTail(Node *&head, int value);
void insertAfterValue(Node *&head, int value,int value1){
    Node *newNode = new Node(value1);
    Node *temp = head;
    while(temp != NULL){
        if(temp->value == value){
            newNode->Next = temp->Prev;
            newNode->Prev = temp->Prev->Prev;
            temp->Prev->Prev->Next = newNode;
            temp->Prev->Prev = newNode;
            return;
        }
        temp = temp->Next;
    }
}
// void insertBeforeVale(Node *&head,int value,int value1){
//     Node *newNode = new Node(value1);
//     Node *temp = head;

// }
void displayDublyLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value;

        if (temp->Next != NULL)
        {
            cout << " --> ";
        }

        temp = temp->Next;
    }
}
bool findValue(Node *&head, int value){
    if(head == NULL){
        return false;
    }
    Node *temp = head;
    while(temp != NULL){
        if(temp->value == value){
            return true;
        }
        temp = temp->Next;
        
    }
    return false;
}
int main(){
    Node *head=NULL;
    int N;
    cin>>N;
    int p[N],n[N],middle[N];
    for(int i=0;i<N;i++){
        cin>>p[i]>>n[i];
        middle[i] = i+1;
    }

    for(int i=0;i<N;i++){
        if(p[i]==0 && n[i]==0){
            if(!findValue(head,middle[i])){
                insertAtHead(head,middle[i]);
            }
        }
        else if(p[i]!=0 && n[i]==0){
            if(!findValue(head,middle[i])){
                insertAtHead(head,middle[i]);
            }
            if(!findValue(head,p[i])){
                insertAtHead(head,p[i]);
            }    
        }
        else if(p[i]==0 && n[i]!=0){
            if(!findValue(head,n[i])){
                insertAtHead(head,n[i]);
            }
            if(!findValue(head,middle[i])){
                insertAtHead(head,middle[i]);
            }
        }
        else if(p[i]!=0 && n[i]!=0){
            if(!findValue(head,n[i])){
                if(findValue(head,middle[i])){

                }
            }
        }
    }

    displayDublyLinkedList(head);
    
}











void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
    newNode->Prev = temp;
}
void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}