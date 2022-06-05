class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> ip, vector<int> op, vector<bool> mp) {
        if (op.size() == ip.size()) {
            res.push_back(op);
        }

        for (int i = 0; i < ip.size(); i++) {
            if (mp[i]) {
                op.push_back(ip[i]);
                mp[i] = false;
                solve(res, ip, op, mp);
                mp[i] = true;
                op.erase(op.end() - 1);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> op;
        vector<bool> mp(nums.size(), true);

        solve(res, nums, op, mp);
        return res;
    }
};