/* temp = head;
    int nextPoint = cum->value;
    int count = 2;
    while (cum->Next != NULL)
    {
        if(cum->value > cum->Next->value){
            
            if(cum->Next->value == 0){
                while (count--)
                {
                    
                    Node *delNode = temp;
                    temp = temp->Next;
                    delete delNode;
                    
            
                }
                displayLinkedList(temp);
                count++;
                cout<<endl;
                
            }
            nextPoint = cum->Next->Next->value;
            cout<<"Antar";
            cout<<cum->Next->value<<" "<<nextPoint<<endl;
            if(cum->Next->value == nextPoint){
                temp = temp->Next;
                while (count--)
                {
                    Node *delNode = temp->Next;
                    temp->Next = temp->Next->Next;
                    delete delNode;
                }
                displayLinkedList(temp);
            }
            
                   
        }
        count += 1;
        cum = cum->Next; */











#include<stdio.h>
#include<string.h>
int top=-1;
char Stack[4]={'\0'};


void Push(char x);
char Pop(void);

int main()
{
    char Str1[4]={'\0'};
    char Str2[4]={'\0'};
    int i;
    strcpy(Str1, "CSE");
    for(i=0; i<3; ++i){
    Push(Str1[i]);
    }
    for(i=0; i<3; ++i){
    Str2[i]=Pop();
    }
    printf("%s", Str2);
    return 0;
}
 
void Push(char x){
  	Stack[++top]=x;
  	return;
}
char Pop(void){
   return Stack[top--];}
