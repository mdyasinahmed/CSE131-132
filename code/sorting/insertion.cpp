#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, pickedValue, i, j;
    cin >> n;

    const int s = 100; // Maximum size
    int a[s];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++)
    {
        pickedValue = a[i];
        j = i - 1;
        while((pickedValue < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = pickedValue;
    }

    // printing array
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
