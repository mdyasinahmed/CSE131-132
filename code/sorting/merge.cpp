#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int right, int mid)
{
    int nL = mid - left + 1;
    int nR = right - mid;

    int *a = new int[nL];
    int *b = new int[nR];

    for (int i = 0; i < nL; i++)
    {
        a[i] = arr[left + i];
    }
    for (int i = 0; i < nR; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < nL && j < nR)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < nL)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < nR)
    {
        arr[k] = b[j];
        k++;
        j++;
    }

    delete[] a;
    delete[] b;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, right, mid);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Sorted array: " << endl;
    mergeSort(arr, 0, size - 1);

    printArray(arr, size);

    return 0;
}
