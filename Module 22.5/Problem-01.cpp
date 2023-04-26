#include<bits/stdc++.h>
#include"MYSTACKantar.h"
using namespace std;

class Node1
{
public:
    char ch;
    Node1 *Next;

    Node1(char ch)
    {
        this->ch = ch;
        Next = NULL;
    }
};


void displayLinkedList(Node1 *&head)
{
    Node1 *temp = head;

    while (temp != NULL)
    {
        cout << temp->ch;

        if (temp->Next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->Next;
    }
}
void insertAtTail(Node1 *&head, char ch){
    Node1 *newNode = new Node1(ch);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node1 *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

bool isPalindrome(Node1 *&head){
    Node1 *slow = head;

    Stack s;

    while(slow != NULL){
        s.push(slow->ch);
        slow = slow->Next;
    }

    while(head != NULL){
        char ch1 = s.Top();
        s.pop();

        if(head->ch != ch1){
            return false;
        }

        head = head->Next;
    }

    return true;
}


int main(){
    Node1 *head = NULL;

    cout<< "Choice 1: Display"<<endl
        << "Choice 2: Insert At Tail"<<endl
        << "Choice 3: Linked List is Palindrome or Not"<<endl
        << "Choice 4: Removed Duplicate in Linked List"<<endl
        <<endl;

    int choice;
    cout << "Next Choice : ";
    cin >> choice;
    char ch;
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
                cout<<"Enter any character : ";
                cin>>ch;

                insertAtTail(head,ch);
            }
            break;

        case 3:
            bool check;
            check = isPalindrome(head);
            if(check){
                cout<<"This Linked List is Palindrome"<<endl;
            }
            else{
                cout<<"This Linked List is Not Palindrome"<<endl;
            }
            break;

        default:
            break;
        }

    
        cout << "Next Choice : ";
        cin >> choice;
    }
}