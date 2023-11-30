#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 505;
vector<int> queens_pos(MAX_N);

bool is_safe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == 1 || board[i][col] == 1 || 
            board[row - i >= 0 ? row - i : 0][col - i >= 0 ? col - i : 0] == 1 ||
            board[row - i >= 0 ? row - i : 0][col + i < N ? col + i : N - 1] == 1)
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<vector<int>> board(N, vector<int>(N, 0));

        for (int i = 0; i < K; ++i) {
            int row, col;
            cin >> row >> col;
            board[row - 1][col - 1] = -1;
        }

        for (int col = 0; col < N; ++col) {
            for (int row = 0; row < N; ++row) {
                if (board[row][col] != -1 && is_safe(board, row, col, N)) {
                    board[row][col] = 1;
                    queens_pos[col] = row + 1;
                    break;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            cout << queens_pos[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
