#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of divisors for a given number
int countDivisors(int num) {
    int divisors = 1;
    for (int i = 2; i * i <= num; ++i) {
        int count = 0;
        while (num % i == 0) {
            num /= i;
            ++count;
        }
        divisors *= (count + 1);
    }
    if (num > 1) {
        divisors *= 2; // If num is a prime number greater than 1
    }
    return divisors;
}

// Function to find the smallest K such that M has the most divisors
int smallestK(int N) {
    int minK = N - 1;
    int maxDivisors = -1;

    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            int divisors = countDivisors(N / i);
            if (divisors > maxDivisors) {
                minK = N / i;
                maxDivisors = divisors;
            }
        }
    }
    return minK;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int result = smallestK(N);
        cout << result << endl;
    }

    return 0;
}
