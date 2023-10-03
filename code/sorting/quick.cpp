#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// function for quick sorting
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int target = start - 1;
        for (int i = start; i < end; i++)
        {
            if (arr[i] < pivot)
            {
                target++;
                swap(arr[i], arr[target]);
            }
        }
        target++;
        swap(arr[end], arr[target]);
        QuickSort(arr, start, target - 1);
        QuickSort(arr, target + 1, end);
    }
}

// function for printing array
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// the main function
int main()
{
    int s;
    cin >> s;
    int arr[s];

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, s - 1);

    printArray(arr, s);

    return 0;
}
