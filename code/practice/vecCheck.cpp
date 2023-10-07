#include<bits/stdc++.h>
using namespace std;

int main() {
    int amount = 8;
    vector <int> table(amount+1, 0);
    table[0] = 1;

    for(int i=0; i<table.size(); i++) {
        cout << table.at(i) << " ";
    }
}