class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int arr[matrix.size()][matrix[0].size()];

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                arr[i][j] = -1;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!matrix[i][j]) {
                    for (int k = 0; k < matrix.size(); k++) {
                        arr[k][j] = 0;
                    }
                    for (int k = 0; k < matrix[i].size(); k++) {
                        arr[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (arr[i][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};