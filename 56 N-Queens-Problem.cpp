class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n) {

        // Check Column
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }

        // Check Row
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }


        // Check Diagonals
        int i = row, j = col;
        while (i >= 0 and j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row; j = col;
        while (i < n and j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j++;
        }

        i = row; j = col;
        while (i >= 0 and j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        i = row; j = col;
        while (i<n and j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void solve(int col, vector<string> board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board.push_back(s);
        }

        solve(0, board, ans, n);

        return ans;
    }
};