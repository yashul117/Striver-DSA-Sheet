class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int r = rowIndex + 1;
        vector<vector<int>> v(r);

        for (int i = 0; i < r; i++) {
            v[i].resize(i + 1);

            v[i][0] = v[i][i] = 1;

            for (int j = 1; j < i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }

        return v[rowIndex];
    }
};