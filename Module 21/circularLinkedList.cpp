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

struct Test
{
    int position[1000];
};

int countingTheSize(Node *&head);
void displayLinkedListCircular(Node *&head);
void displayLinkedList(Node *&head);
void insertAtHead(Node *&head, int value);
void insertAtTail(Node *&head, int value);
void insertAtSpecificPosition(Node *&head, int position, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);

int main()
{
    Node *head = NULL;

    cout << "Choice-0: Exit" << endl
         << "Choice-1: Display(circular)"<<endl
         << "Choice-2: Display(linear)"<<endl
         << "Choice-3: Insertion at Head" << endl
         << "Choice-4: Insertion at Tail" << endl
         << "Choice-5: Insertion at Specific Position" << endl
         << "Choice-6: Deletion at Head" << endl
         << "Choice-7: Deletion at Tail" << endl
         << endl;

    int choice, value, position;
    cout << "Next Choice : ";
    cin >> choice;

    while(choice != 0){
        switch(choice){
        case 1:
            displayLinkedListCircular(head);
            break;

        case 2:
            displayLinkedList(head);
            break;

        case 3:

            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 4:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        // case 5:
        //     cout << "Enter the value : ";
        //     cin >> value;
        //     cout << "Enter the Desired Position : ";
        //     cin >> position;
        //     if (position > countingTheSize(head) && position < 1)
        //     {
        //         cout << "This position is not valid " << endl;
        //         break;
        //     }
        //     insertAtSpecificPosition(head, position, value);
        //     break;

        case 6:
            deletionAtHead(head);
            break;

        case 7:
            deletionAtTail(head);
            break;

        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
        if(choice==0){
            cout<<"Total length : "<<countingTheSize(head)<<endl;
        }
    }

}
int countingTheSize(Node *&head)
{
    Node *temp = head;
    int count = 0;

    do
    {
        temp = temp->Next;
        count++;
    }
    while (temp != head);

    return count;
}
void displayLinkedListCircular(Node *&head)
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
void displayLinkedList(Node *&head){
    if(head == NULL){
        cout<<"The Linked List is Empty"<<endl;
        return;
    }
    Node *temp = head;
    do{
        cout<<temp->value;
        temp = temp->Next;
        if(temp != head){
            cout<<" -> ";
        }
    }
    while(temp != head);
    cout<<endl; 
}
void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->Next = head;

    if(head == NULL){
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    while(temp->Next != head){
        temp = temp->Next;
    }
    temp->Next = newNode;

    head = newNode;
}
void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }

    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }

    newNode->Next = head;
    temp->Next = newNode;
}
void insertAtSpecificPosition(Node *&head, int position, int value)
{
    if (position == 1)
    {
        insertAtHead(head, value);
        return;
    }

    Node *temp = head;
    Node *newNode = new Node(value);
    int i = 0;

    while (i < position - 2)
    {
        temp = temp->Next;
        i++;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
        delete delNode;
        
    }
    else
    {
        cout << "There is no Node in the Linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;

    if (temp != NULL && temp->Next != head)
    {
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "There is no Node in the Linked List" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

