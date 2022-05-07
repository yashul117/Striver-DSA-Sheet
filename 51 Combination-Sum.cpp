class Solution {
public:
//     int sum(vector<int> v) {
//         int s=0;
//         for(int i=0;i<v.size();i++) {
//             s+=v[i];
//         }

//         return s;
//     }

    void solve(vector<vector<int>> &res, vector<int> ip, vector<int> op, int i, int sum, int target)
    {
//         if(sum(op)==target) {
//             res.push_back(op);
//             return;
//         }

//         if(sum(op)>target) {
//             return;
//         }

        if (i >= ip.size())
            return;

        if (ip[i] + sum == target) {
            op.push_back(ip[i]);
            res.push_back(op);
            return;
        }

        if (ip[i] + sum < target) {
            vector<int> op1 = op;
            vector<int> op2 = op;
            // int s=ip[0];


            // if(s+sum>target) {
            //     ip.erase(ip.begin()+0);
            //     s=ip[0];
            // }
            op2.push_back(ip[i]);

            solve(res, ip, op1, i + 1, sum, target);
            solve(res, ip, op2, i, sum + ip[i], target);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& ip, int target) {
        vector<vector<int>> res;

        vector<int> op;
        sort(ip.begin(), ip.end());

        solve(res, ip, op, 0, 0, target);

        return res;
    }
};