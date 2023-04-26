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
// void reverseDoublyLinkedList(doublyNode *&head){
//     doublyNode *temp = NULL;
//     doublyNode *current = head;

//     while (current != NULL);
//     {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev; 
//     }
//     if(temp != NULL){
//         head = temp->prev;
//     }
    
// }

void reverse(doublyNode *&head){
    doublyNode *temp = NULL;
    doublyNode *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL){
        head = temp->prev;
    }
    
}



int main(){
    doublyNode *head = NULL;
    cout << "Choice-0: Exit" << endl
         << "Choice-1: Display List" << endl
         << "Choice-2: Insertion at Tail" << endl
         << "Choice-3: reverseDoublyLinkedList"<<endl
         <<endl;

    int choice, value, position;
    cout << "Next Choice : ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            displayDublyLinkedList(head);
            cout<<endl;
            break;

        case 2:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            reverse(head);
            break;
        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
    }
    
    

}





