class Solution {
public:
    double myPow(double x, int n) {
//         long no=n;
//         double ans=1;
//         if(n<0) {
//             no=no*-1;
//         }

//         if(n<0) {
//             double res=1.0;
//             for(int i=1;i<=no;i++) {
//                 res=res/x;
//             }
//             return res;
//         }

//         for(int i=1;i<=n;i++) {
//             ans=ans*x;
//         }
//         return ans;

        double ans = 1.0;
        long long temp = n;

        if (temp < 0) {
            temp = -1 * temp;
        }
        while (temp) {
            if (temp % 2) {
                ans = ans * x;
                temp = temp - 1;
            }
            else {
                x = x * x;
                temp = temp / 2;
            }
        }

        if (n < 0) {
            return (double)1.0 / ans;
        }
        else {
            return ans;
        }
    }
};