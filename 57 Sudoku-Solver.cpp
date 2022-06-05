class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char val) {
        int row = i - i % 3;
        int col = j - j % 3;

        for (int k = 0; k < 9; k++) {
            if (board[k][j] == val)
                return false;
        }
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == val)
                return false;
        }

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[row + k][col + l] == val)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return solve(board, i + 1, 0);

        if (board[i][j] != '.')
            return solve(board, i, j + 1);

        for (int c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1))
                    return true;

                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};