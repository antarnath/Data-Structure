#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int current){
    int largest = current;
    int leftChild = current*2 + 1;
    int rightChild = current*2 + 2;

    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    if(largest != current){
        swap(arr[largest],arr[current]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int nonleafStart = (n/2)-1;

    cout<<"After heapify: ";
    printArray(arr,n);
    for(int i=nonleafStart;i>=0;i--){
        heapify(arr,n,i);
    }
    cout<<"Before heapify: ";
    printArray(arr,n);



    cout<<endl;
    cout<<"Sort Array: ";
    heapSort(arr,n);
    printArray(arr,n);

    return 0;
}