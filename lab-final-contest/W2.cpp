// #include <iostream>
// #include <vector>

// using namespace std;

// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int N, K;
//         cin >> N >> K;

//         int sum = N * (N + 1) / 2;
//         if (K > sum) {
//             cout << "-1\n"; // No solution possible
//             continue;
//         }

//         vector<int> arr(N, 1);
//         for (int i = N - 1; i >= 0; --i) {
//             if (sum - arr[i] >= K) {
//                 sum -= arr[i];
//                 arr[i] *= -1;
//             }
//         }

//         for (int i = 0; i < N; ++i) {
//             if (arr[i] < 0) {
//                 arr[i] *= -1;
//             }
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
