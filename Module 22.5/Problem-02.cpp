#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int value)
    {
        this->value = value;
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
void insertAtTail(Node *&head, int value){
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
void removeDuplicate(Node *&head){
    Node *temp = head;
    if(temp == NULL){
        cout<<"There is No Node"<<endl;
        return;
    }
    if(temp->Next == NULL){
        return;
    }

    Node *next_next = temp->Next;
    while(temp != NULL  && next_next != NULL){
        if(temp->value == next_next->value){
            Node *delNode = temp->Next;
            temp->Next = next_next->Next;
            next_next = temp->Next;

        }
        else{
            temp = temp->Next;
            next_next = next_next->Next;
        }
    }

}
void rotatedLinkedList(Node *&head, int value){
    
}



int main(){
    Node *head = NULL;

    cout<< "Choice 1: Display"<<endl
        << "Choice 2: Insert At Tail"<<endl
        << "Choice 3: Removed Duplicate in Linked List"<<endl
        <<endl;

    int choice;
    cout << "Next Choice : ";
    cin >> choice;
    int value;
    while(choice != 0){
        switch(choice){
        
        case 1:
            displayLinkedList(head);
            cout<<endl;
            break;

        case 2:
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Enter value : ";
                cin>>value;
                insertAtTail(head,value);
            }
            break;

        case 3:
            removeDuplicate(head);
            break;

        case 4:
            int value;
            cin>>value;
            rotatedLinkedList(head,value);
            break;
        default:
            break;
        }

    
        cout << "Next Choice : ";
        cin >> choice;
    }
}