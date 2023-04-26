#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int globalID = 100;
class person{
    string name;
    int id;
    float salary;

public:
    person(){
        name = "";
        id = -1;
        salary = -1.0;
    }
    void setName(string name){
        this->name = name;
    }
    void setSalary(float salary){
        this->salary = salary;
    }
    person(string name, float salary){
        setName(name);
        setSalary(salary);
        this->id = globalID;
        globalID++;
    }

    int getID(){
        return id;

    }   
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }

    void print(){
        cout<< name <<" | "<< id <<" | "<< salary<<endl;
    }

};

int main(){

    Stack <person> st;
    person a ("Antar Nath", 654.6);
    person b ("Ria Moni", 200.6);
    person c ("Sakib Mia", 354.7);
    st.push(a);
    st.push(b);
    st.push(c);

    while(!st.empty()){
        person printObj = st.pop();
        printObj.print();
    }

    st.Top();
    return 0;





























    // Stack <pair<int,char>> st;

    // st.push(make_pair(1,'a'));
    // st.push(make_pair(5,'b'));
    // st.push(make_pair(7,'c'));

    // while(!st.empty()){
    //     pair <int,char> chk;
    //     chk = st.pop();
    //     cout<<chk.first<<" "<<chk.second<<endl;
    //     // cout<<st.pop()<<endl;
    // }

    // cout<< st.size()<<endl;
    // if(!st.empty()){
    //     pair <int,char> chk;
    //     chk = st.pop();
    //     cout<<chk.first<<" "<<chk.second<<endl;
    // }
    
    // // cout<<st.Top()<<endl;
}