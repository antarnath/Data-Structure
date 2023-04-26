#include <bits/stdc++.h>
using namespace std;

int antar = 0;
class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void displayLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value;

        if (temp->Next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->Next;
    }
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
}


Node* removeSumOfZero(Node *head){
    Node *temp = head;
    Node *New = NULL;

    while (temp!= NULL)
    {
        Node *tem = temp;
        int sum = 0;
        while (tem!= NULL)
        {
            sum += tem->value;
            if(sum == 0){
                temp = tem;
                break;
            }
            tem = tem->Next;
            
        }
        if(sum != 0 ){
            insertAtTail(New,temp->value);
        }
        temp = temp->Next;
             
    }

    return New;
    
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

    head = removeSumOfZero(head);

    displayLinkedList(head);
    
    return 0;
    
}