#include<bits/stdc++.h>
using namespace std;

#define s 1000

// Function to Swap 2 value Address
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Function for Selection Sort Operation
void selectionSort(int array[], int size)
{
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        swap(array[minIndex], array[i]);
    }
}

// Function to Print an Array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int a[s];
    cout << "Enter Size & Array: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);
    cout << "Array after Sorting: ";
    printArray(a, n);

    return 0;
}
