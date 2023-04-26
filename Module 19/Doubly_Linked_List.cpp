#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode* prev;
    doublyNode* next;

    doublyNode(int value){
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

int countingTheSize(doublyNode *&head);
void displayDublyLinkedList(doublyNode *&head);
void displayDublyLinkedListReverse(doublyNode *&head);
void insertAtTail(doublyNode *&head, int value);
void insertAtHead(doublyNode *&head, int value);
int midValueReturn(doublyNode *&head);

int main(){
    doublyNode *head = NULL;
    cout << "Choice-0: Exit" << endl
         << "Choice-1: Counting the Size" << endl
         << "Choice-2: Display List" << endl
         << "Choice-3: Display List Reverse"<<endl
         << "Choice-4: Insertion at Head" << endl
         << "Choice-5: Insertion at Tail" << endl
         << "Choice-20: Find midle value in Linked List"<<endl
         <<endl;

    int choice, value, position;
    cout << "Next Choice : ";
    cin >> choice;
    while (choice != 0){
        switch (choice)
        {
        case 1:
            cout << "Length of Doubly Linked List : "
                 << countingTheSize(head)
                 << endl;
            break;

        case 2:
            if (head == NULL)
            {
                cout << "There is no Doubly Node" << endl;
                break;
            }
            cout << "Doubly Linked List : ";
            displayDublyLinkedList(head);
            cout << endl;
            break;

        case 3: 
            if(head == NULL){
                cout<<"There is no Doubly Node"<<endl;
                break;
            }
            displayDublyLinkedListReverse(head);
            cout<<endl;
            break;

        case 4:

            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 5:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 20:
            int midvalue;
            midvalue = midValueReturn(head);
            cout<<"Midle value : "<<midvalue<<endl;
            break;

        default:
            break;
        }
        cout<<"Next Choice : ";
        cin>>choice;
    }

    return 0;
}

int countingTheSize(doublyNode *&head)
{
    doublyNode *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}
void displayDublyLinkedList(doublyNode *&head)
{
    doublyNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->value;

        if (temp->next != NULL)
        {
            cout << " --> ";
        }

        temp = temp->next;
    }
}
void displayDublyLinkedListReverse(doublyNode *&head){
    doublyNode *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp != NULL){
        cout<<temp->value;
        if(temp->prev != NULL){
            cout<<" --> ";
        }
        temp = temp->prev;
    }
}
void insertAtTail(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtHead(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
int midValueReturn(doublyNode *&head){
    doublyNode *temp = head;
    doublyNode *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }

    while (1)
    {
        if(temp->value == temp1->value){
            return temp1->value;
        }
        temp = temp->next;
        temp1 = temp1->prev;
    }
}


