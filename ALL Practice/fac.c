#include<stdio.h>


int factorial(int n){
    if(n==0){
        return 1;   //base case
    }

    return n*factorial(n-1);
}

int main(){
    int n;
    printf("Enter the value : ");
    scanf("%d",&n);

    int fac = factorial(n);

    printf("%d",fac);

}