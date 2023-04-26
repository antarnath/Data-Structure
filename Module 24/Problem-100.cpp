#include<iostream>
using namespace std;

int main() {
    int a[100+5];
    int b[100+5];
    int val[100+5];
    int n,head;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		val[i] = i;
		if(!head && !a[i]) {
			head = val[i];
		}
	}
	int num = head;
    while(b[num] != head){
        bool flag = true;
        if(b[num]){
            num = b[num];
        }
        else{
            for(int i=1;i<=n;i++){
                if(i == head){
                    continue;
                }
                if(!a[i]){
                    a[i] = val[num];
                    b[num] = val[i];
                    num = val[i];
                    flag = false;
                    break;
                    
                }
            }
            if(flag){
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i] <<" "<<b[i]<<endl;
    }

}