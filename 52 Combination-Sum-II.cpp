class Solution {
public:
    void solve(set<vector<int>> &res, vector<int> ip, vector<int> op, int target) {
        if (target == 0) {
            res.insert(op);
            return;
        }
        if (target < 0)
            return;
        if (ip.size() == 0)
            return;

        vector<int> op1 = op;
        vector<int> op2 = op;

        int temp = ip[0];
        op2.push_back(temp);

        ip.erase(ip.begin() + 0);

        solve(res, ip, op1, target);
        solve(res, ip, op2, target - temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& ip, int target) {
        int sum = accumulate(ip.begin(), ip.end(), 0);

        set<vector<int>> res;
        vector<vector<int>> ans;

        vector<int> op;


        if (sum < target) {
            return ans;
        }
        if (sum == target) {
            ans.push_back(ip);
            return ans;
        }

        sort(ip.begin(), ip.end());

        solve(res, ip, op, target);

        for (auto it = res.begin(); it != res.end(); it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};