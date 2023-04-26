#include<bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<char>&st, char chkElement){
    if(st.empty()){
        st.push(chkElement);
        return;
    }

    char topElement = st.top();
    st.pop();
    insertAtBottom(st,chkElement);

    st.push(topElement);


}
void reverseStack(stack<char>&st){
    if(st.empty())  return;

    char topElement = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,topElement);
}

string output(string str){
	stack<char>st;
    string str2 = "";
	for(int i=0;i<str.length();i++){
		if(str[i]>='a' && str[i]<='z'){
			st.push(str[i]);
		}
        else{
            string ans="";
            reverseStack(st);
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }

            str2 = ans + str2;
        }
	}

    return str2;
	
}

int main(){
	string str;
	cin>>str;

	string str2;
	str2 = output(str);

	cout<<str2<<endl;
}