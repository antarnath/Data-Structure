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
void displayLinkedList(Node *&head);
void insertAtHead(Node *&head, int value);
void insertAtTail(Node *&head, int value);
void insertAtSpecificPosition(Node *&head, int position, int value);
int searchByValueUnique(Node *&head, int value);
void searchByValueDuplicate(Node *&head, int value);
Test searchByValueDuplicateReturn(Node *&head, int value);
void insertAfterASpecificValueUnique(Node *&head, int searchValue, int value);
void insertAfterASpecificValueDuplication(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtASpecificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int value);
void deletionByValueDuplicate(Node *&head, int value);
Node* reverseNonRecursive(Node *&head);
Node* reverseRecursive(Node *&head);
int findMid(Node *&head);
void makeCycle(Node *&head, int pos);
bool detectCycle(Node *&head);
void deleteCycle(Node *&head);
// Node* reverseAtSpecificPositionByRecursive(Node *&head, int value);

int main()
{
    Node *head = NULL;

    cout << "Choice-0: Exit" << endl
         << "Choice-1: Counting the Size" << endl
         << "Choice-2: Display List" << endl
         << "Choice-3: Insertion at Head" << endl
         << "Choice-4: Insertion at Tail" << endl
         << "Choice-5: Insertion at Specific Position" << endl
         << "Choice-6: Search a value (Unique List)" << endl
         << "Choice-7: Search a value (Duplication enabled List)(print in function)" << endl
         << "Choice-8: Search a value (Duplication enabled List)(print in main function)" << endl
         << "Choice-9: Insertion after a specific value (Unique List)" << endl
         << "Choice-10: Insertion after a specific value (Duplication enable List)" << endl
         << "Choice-11: Deletion at Head" << endl
         << "Choice-12: Deletion at Tail" << endl
         << "Choice-13: Deletion at Specific Position" << endl
         << "Choice-14: Deletion by value (Unique List)" << endl
         << "Choice-15: Deletion by value (Duplication enable List)" << endl
         << "Choice-16: reverse Linked List (Non Recursive)"<<endl
         << "Choice-17: Reverse Linked List (Recursive way)"<<endl
         << "Choice-18: Finding the Mid (Slow-Fast Pointer Method)"<<endl
         << "Choice-19: Create a Cycle At Kth Position"<<endl
         << "Choice-20: Detect Cycle in the List"<<endl
         << "Choice-21: Delete Cycle in the List"<<endl
        //  << "Choice-18: Reverse Linked List at specific position"<<endl
         << endl;

    int choice, value, position;
    cout << "Next Choice : ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Length of Linked List : "
                 << countingTheSize(head)
                 << endl;
            break;

        case 2:
            if (head == NULL)
            {
                cout << "There is no Node" << endl;
                break;
            }
            cout << "Linked List : ";
            displayLinkedList(head);
            cout << endl;
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

        case 5:
            cout << "Enter the value : ";
            cin >> value;
            cout << "Enter the Desired Position : ";
            cin >> position;
            if (position > countingTheSize(head) && position < 1)
            {
                cout << "This position is not valid " << endl;
                break;
            }
            insertAtSpecificPosition(head, position, value);
            break;

        case 6:
            if (head == NULL)
            {
                cout << "There is no Node " << endl;
                break;
            }
            cout << "Enter the Value to Search : ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "The number is at Position : " << position << endl;
            }
            else
            {
                cout << "The number is not yet in the List " << endl;
            }
            break;

        case 7:
            if (head == NULL)
            {
                cout << "There is no Node " << endl;
                break;
            }
            cout << "Enter the value to search : ";
            cin >> value;
            searchByValueDuplicate(head, value);
            break;

        case 8:
            if (head == NULL)
            {
                cout << "There is no Node " << endl;
                break;
            }
            cout << "Enter the value to search : ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);

            if (T.position[0] == 1)
            {
                cout << "The number is not yet in the List " << endl;
            }
            else
            {
                int size = T.position[0];

                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i] << " ";
                    if (i < size - 1)
                    {
                        cout << ",";
                    }
                }
                cout << endl;
            }
            break;
        case 9:
            if (head == NULL)
            {
                cout << "There is no Node " << endl;
                break;
            }
            int searchValue;
            cout << "Enter the value to search : ";
            cin >> searchValue;
            cout << "Enter the value to insert : ";
            cin >> value;
            insertAfterASpecificValueUnique(head, searchValue, value);
            break;

        case 10:
            if (head == NULL)
            {
                cout << "There is no Node " << endl;
                break;
            }
            cout << "Enter the value to search : ";
            cin >> searchValue;
            cout << "Enter the value to insert : ";
            cin >> value;
            insertAfterASpecificValueDuplication(head, searchValue, value);
            break;

        case 11:
            deletionAtHead(head);
            break;

        case 12:
            deletionAtTail(head);
            break;

        case 13:
            cout << "Enter the Desired Position : ";
            cin >> position;
            if (head == NULL)
            {
                cout << "There is No value in the  Linked List" << endl;
                break;
            }
            deletionAtASpecificPosition(head, position);
            break;

        case 14:
            cout << "Enter the Value : ";
            cin >> value;
            deletionByValueUnique(head, value);
            break;

        case 15:
            cout << "Enter the Value : ";
            cin >> value;
            deletionByValueDuplicate(head, value);
            break;

        case 16:
            head = reverseNonRecursive(head);
            break;

        case 17:
            head = reverseRecursive(head);
            break;

        case 18:
            int mid;
            mid = findMid(head);
            if(mid == -1){
                cout<<"The Linked list is empty"<<endl;
            }
            else{   
                cout<<"Mid value is "<<mid<<endl;
            }
            break;

        case 19:
            cout<<"Enter any Position : ";
            cin>>position;
            makeCycle(head,position);
            break;

        case 20:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus){
                cout<<"There is a Cycle in the List"<<endl;
            }
            else{
                cout<<"There is no Cycle in the List"<<endl;
            }
            break;

        case 21:
            bool cycle;
            cycle = detectCycle(head);
            if(cycle){
                deleteCycle(head);
            }
            else{
                cout<<"There is no Cycle in the List"<<endl;
            }
            break;
        // case 18:
        //     cout<<"Test Case : ";
        //     int t;
        //     cin>>t;
        //     for(int i=1;i<=t;i++){
        //         cout<<"Enter any Number : ";
        //         cin>> value;
        //         Node *newHeaD = head;
        //         cout<<"before reverse  ";
        //         displayLinkedList(head);
        //         cout<<endl;
        //         Node *temp = NULL;
        //         temp = reverseAtSpecificPositionByRecursive(newHeaD,value);
        //         cout<<"After reverse: ";
        //         displayLinkedList(temp);
        //         cout<<endl;
        //     }
        // break;

        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
    }
    return 0;
}

int countingTheSize(Node *&head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }

    return count;
}
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
void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->Next = head;
    head = newNode;
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
int searchByValueUnique(Node *&head, int value)
{
    Node *temp = head;
    int count = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp->value != value)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}
void searchByValueDuplicate(Node *&head, int value)
{
    Node *temp = head;
    int size = countingTheSize(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == value)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    position[0] = k;
    if (flag == 0)
    {
        cout << "The number is not yet in the List " << endl;
    }
    else
    {
        cout << "The number is at Position : ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i] << " ";
            if (i < position[0] - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
    }
}
Test searchByValueDuplicateReturn(Node *&head, int value)
{
    Node *temp = head;
    Test T;
    int count = 1;
    int k = 1;

    while (temp != NULL)
    {
        if (temp->value == value)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    T.position[0] = k;
    return T;
}
void insertAfterASpecificValueUnique(Node *&head, int searchValue, int value)
{
    int position = searchByValueUnique(head, searchValue);
    insertAtSpecificPosition(head, position + 1, value);
}
void insertAfterASpecificValueDuplication(Node *&head, int searchValue, int value)
{
    Test T;
    T = searchByValueDuplicateReturn(head, searchValue);
    int size = T.position[0];
    for (int i = 1; i < size; i++)
    {
        insertAtSpecificPosition(head, T.position[i] + i, value);
    }
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no Node in the Linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;

    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
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
void deletionAtASpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (0 < position && position <= countingTheSize(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countingTheSize(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "This value Position is Out of Bound" << endl;
    }
}
void deletionByValueUnique(Node *&head, int value)
{
    int position;
    position = searchByValueUnique(head, value);
    deletionAtASpecificPosition(head, position);
}
void deletionByValueDuplicate(Node *&head, int value)
{
    Test T;
    T = searchByValueDuplicateReturn(head, value);
    int size = T.position[0];
    for (int i = 1; i < size; i++)
    {
        deletionAtASpecificPosition(head, T.position[i] - i + 1);
    }
}
Node* reverseNonRecursive(Node *&head){
    Node *prev = NULL;
    Node *current = head;
    if(head == NULL){
        cout<<"The Linked List is Empty"<<endl;
        return head;
    }
    Node *next = head->Next;

    while(true){
        current->Next = prev;
        prev = current;
        current = next;
        if(current == NULL)
            break;
        next = next->Next;
    }

    return prev;
}
Node* reverseRecursive(Node *&head){
    if(head == NULL || head->Next == NULL){
        if(head==NULL) cout<<"The Linked List is Empty"<<endl;
        return head;
    }
    Node* newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;

}

int findMid(Node *&head){
    
    if(head == NULL){
        return -1;
    }
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->Next != NULL){
        fast = fast->Next->Next;
        slow = slow->Next;
    }
    return slow->value;
}
void makeCycle(Node *&head, int pos){
    Node *temp = head;
    Node *startNode;
    int count=1;

    while(temp->Next != NULL){
        if(count == pos){ 
            startNode = temp;
        }
        temp = temp->Next;
        count++;
    }
    temp->Next = startNode;
}
bool detectCycle(Node *&head){
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->Next != NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
        
        //Cycle Check
        if(slow->Next == fast->Next){
            return true;
        }
    }
    return false;
}

void deleteCycle(Node *&head){
    if(detectCycle(head)){
        Node *fast = head;
        Node *slow = head;

        while(fast != NULL && fast->Next != NULL){
            slow = slow->Next;
            fast = fast->Next->Next;

            if(slow->Next == fast->Next){
                break;
            }
        }

        fast = head;
        while(fast->Next != slow->Next){
            fast = fast->Next;
            slow = slow->Next;
        }
        slow->Next = NULL;

    }
    else{
        cout<<"There is no Cycle in the List"<<endl;
    }
}


// Node* reverseAtSpecificPositionByRecursive(Node *&head, int value){
//     Node *temp = head;
//     if(antar > value-2){
//         return temp;
//     }
//     antar++;
//     Node *newHead = reverseAtSpecificPositionByRecursive(temp->Next,value);
//     temp->Next->Next = temp;
//     temp->Next = NULL;
//     return newHead;
// }





// antar