#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j<high; j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[pivot]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int arr[5] = {5, 10, 40, 3, 9};

    quickSort(arr, 0, 4);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}
