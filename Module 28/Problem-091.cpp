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
Node* removeSumOfTen(Node *&head,int n){
    Node *temp = head;

    Node *cum = NULL;
    int pre,nex;
    pre = temp->value;
    insertAtTail(cum,pre);
    temp = temp->Next;
    while (temp != NULL)
    {
        nex = pre + temp->value;
        insertAtTail(cum,nex);
        pre = nex;
        temp = temp->Next;

    }

    temp = head;

    int count=1;

    while (cum->Next != NULL)
    {
        if(cum->value > cum->Next->value){
            if(cum->Next->value == 0){
                count++;
                while (count--)
                {
                    Node* delNode = temp;
                    temp = temp->Next;
                    delete delNode;
                }
                
            }
        }
        count++;
        cum = cum->Next;
    }

    Node *newtemp = temp;
    

    cum = NULL;
    pre = temp->value;
    insertAtTail(cum,pre);
    temp = temp->Next;
    while (temp != NULL)
    {
        nex = pre + temp->value;
        insertAtTail(cum,nex);
        pre = nex;
        temp = temp->Next;

    }

    temp = newtemp;
    int nexPoint = cum->value;
    count = 0;
    while (cum->Next != NULL)
    {
        if(cum->value > cum->Next->value)
        {
            if(nexPoint == cum->Next->value){
                count++;
                while (count--)
                {
                    Node *delNode = temp->Next;
                    temp->Next = delNode->Next;
                    delete delNode;
                }
            }
            else{
                while (count-- && temp != NULL)
                {
                    temp = temp->Next;
                }
                nexPoint = cum->Next->value;
                
            }  
        }

        count++;
        cum = cum->Next;
    }
    













    //   displayLinkedList(temp);

    return temp;
    
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

    head = removeSumOfTen(head,n);

      displayLinkedList(head);
    
}