#include<iostream>
using namespace std;

void merge(int A[], int b, int m, int e){
    int s1 = m-b+1;
    int s2 = e-m;
    int L[s1], R[s2];
    for(int i=0; i<s1; i++){
        L[i] = A[b+i];
    }
    for(int i=0; i<s2; i++){
        R[i] = A[m+1+i];
    }

    int l =0;
    int r = 0;
    int p = b;

    while(l<s1 && r<s2)
    {
        if(R[r]<L[l]){
            A[p] = R[r];
            r++;
        }
    } 
}

void mergeSort(int A[], int b, int e){
    int m;
    if(b<e){
        return;
    }
    m = (b+(e-b))/2;
    mergeSort(A, b, m);
    mergeSort(A, m+1, e);
    merge(A, b, m, e);
}

int main(){
    // int size;
    // cin>>size;
    // int arr[size];
    // for(int i=0; i<size; i++){
    //     cin>>arr[i];
    // }

    // int arr[4] = {4,5,1,0};
    // mergeSort(arr,0,3);
    
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    int arr[4] = {3, 2 ,4 ,1};
    
    mergeSort(arr, 0, 4);

    for(int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}