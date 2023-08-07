#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }

    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        //cout<<i<<endl;
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--){
        //cout<<" before swap  "<<arr[0]<<" "<<arr[i]<<endl;
        swap(arr[0], arr[i]);
        //cout<<"  after swap   "<<arr[0]<<" "<<arr[i]<<endl;
        heapify(arr, i, 0);
    }
}

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    heapSort(arr, size);
    
    for(int i=0; i<size; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

}