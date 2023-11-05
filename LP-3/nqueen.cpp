#include<bits\stdc++.h>
using namespace std;

class NQueens {
public:
    NQueens(int boardSize) {
        size = boardSize;
        board = vector<vector<bool>>(size, vector<bool>(size, false));
        count = 0;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j]) {
                    cout << "Q ";
                } else {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isSafe(int row, int col) {
        // Check Column (above and below of (row, col))
        for (int i = 0; i < size; i++) {
            if (board[i][col]) {
                return false;
            }
        }

        // Check backward slash (\) diagonal only in above direction
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j--;
        }

        // Check backward slash (\) diagonal only in below direction
        i = row;
        j = col;
        while (i < size && j < size) {
            if (board[i][j]) {
                return false;
            }
            i++;
            j++;
        }

        // Check forward slash (/) diagonal only in above direction
        i = row;
        j = col;
        while (i >= 0 && j < size) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j++;
        }

        // Check forward slash (/) diagonal only in below direction
        i = row;
        j = col;
        while (i < size && j >= 0) {
            if (board[i][j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void setFirstQueenPosition() {
        cout << "Enter coordinates of the first queen: " << endl;
        int row, col;
        cout << "Enter row (1-" << size << "): ";
        cin >> row;
        cout << "Enter column (1-" << size << "): ";
        cin >> col;
        board[row - 1][col - 1] = true;
       // printBoard();
    }

    void solve(int row) {
        if (row == size) {
            count++;
            printBoard();
            return;
        }

        if (any_of(board[row].begin(), board[row].end(), [](bool x) { return x; })) {
            solve(row + 1);
            return;
        }

        for (int col = 0; col < size; col++) {
            if (isSafe(row, col)) {
                board[row][col] = true;
                solve(row + 1);
                board[row][col] = false;
            }
        }
    }

    void displayMessage() {
        if (count > 0) {
            cout << "Solution exists for the given position of the queen." << endl;
            //printBoard();
        } else {
            cout << "Solution doesn't exist for the given position of the queen." << endl;
        }
    }

private:
    int size;
    vector<vector<bool>> board;
    int count;
};

int main() {
    int N;
    cout << "Enter the size of the chessboard: ";
    cin >> N;
    NQueens solver(N);
    solver.setFirstQueenPosition();
    solver.solve(0);
    
    solver.displayMessage();
    return 0;
}
