class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size(), c = matrix[0].size();
        int row = -1;
        for (int i = 0; i < r; i++) {
            if (matrix[i][c - 1] == target)
                return true;
            else if (matrix[i][c - 1] > target) {
                row = i;
                break;
            }
        }
        if (row < 0)
            return false;

        if (binary_search(matrix[row].begin(), matrix[row].end(), target)) {
            return true;
        }
        return false;
    }
};