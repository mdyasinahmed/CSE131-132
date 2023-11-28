#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        // If it's impossible to find x and y satisfying the conditions
        if (2 * l > r) {
            cout << "-1 -1" << endl;
        } else {
            // We can take x as l and y as 2*l
            cout << l << " " << 2 * l << endl;
        }
    }

    return 0;
}
