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
void insertAfterSpecificValue(Node *&head,int searchValue,int value){
    Node *newNode = new Node(value);

    Node *temp = head;

    while (temp->value != searchValue)
    {
        temp = temp->Next;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
    
}
void deletionAtHead(Node *&head){
    Node *delNode = head;
    head = delNode->Next;
    delete delNode;
}
void createCircularList(Node *&head){
    Node *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = head;
    
}



int main(){
    Node *head = NULL;

    cout<<"Choice-0: Exit"<<endl
        <<"Choice-1: display"<<endl
        <<"Choice-2: insertAtTail"<<endl
        <<"Choice-3: Insertion after a specific value (Unique List)" << endl
        <<"Choice-4: Deletion by value (Unique List)" << endl
        <<endl;

    int choice,value,position;
    cout<<"Next Choice : ";
    cin>>choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:

            if (head == NULL)
            {
                cout << "There is no Node" << endl;
                break;
            }
            cout << "Linked List : ";
            displayLinkedList(head);
            cout << endl;
            break;
        
        case 2:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            int searchValue;
            cin>>searchValue;
            cin>>value;
            insertAfterSpecificValue(head,searchValue,value);
            break;

        case 4:
            deletionAtHead(head);
            break;

        case 5:
            createCircularList(head);

        default:
            break;
        }

        cout<<"Next Choice : ";
        cin>>choice;
    }
    
}