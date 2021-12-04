class Solution {
public:
    /*
        int rec(int i,int j,int m,int n,vector<vector<int>>mat) {
            //Recursive
            if(i==m||j==n) {
                return 0;
            }

            if(i==m-1&&j==n-1) {
                return 1;
            }

            return rec(i+1,j,m,n)+rec(i,j+1,m,n);

            //Memoiziation

            if(i==m||j==n) {
                return 0;
            }

            if(i==m-1&&j==n-1) {
                return 1;
            }

            if(mat[i][j]!=-1) {
                return mat[i][j];
            }

            return mat[i][j]=rec(i+1,j,m,n,mat)+rec(i,j+1,m,n,mat);

        }
    */

    int uniquePaths(int m, int n) {
        // Ans by combinatrics

        double ans = 1;

        int td = m + n - 2; //total directions = (m-1) + (n-1)

        // Find C(m+n-2,m-1) or C(m+n-2,n-1)

        for (int i = 1; i <= n - 1; i++) {
            ans = ans * ((m + n - 2) - (n - 1) + i) / i;
        }
        return ans;
    }
};