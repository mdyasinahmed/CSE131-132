#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {
  for(int i=1; i<size; i++) {
    int key = arr[i];
    int j = i-1;

    while(key<arr[j] && j>=0){
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = key;
  }

  for(int i=0; i<size; i++) {
    cout<<arr[i]<< " ";
  }
  cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];

    // scan array
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    //calling function for insertion sort
    insertionSort(a,n);


}

