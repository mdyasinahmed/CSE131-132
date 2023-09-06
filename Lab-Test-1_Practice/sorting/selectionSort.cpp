#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int a_size) {
    for(int step = 0; step = a_size-1; step++) {
        int minIndex = step;
        for(int i=step+1; i<a_size; i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        swap(&arr[minIndex], &arr[step]);
    }
}

void print(int arr[], int n) {
    for(int i=0; i<n; i++) { 
        cout << arr[i] <<" ";
    }
}

int main() {
    int n; 
    cin >> n; 
    int arr[n];

    for(int i=0; i<n; i++) { 
        cin >> arr[i]; 
    }

    selectionSort(arr, n);
    print(arr, n);
    
}