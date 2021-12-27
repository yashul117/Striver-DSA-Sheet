class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> temp;
        temp = intervals[0];

        vector<vector<int>> ans;

        for (auto x : intervals) {
            if (x[0] <= temp[1]) {
                temp[1] = max(temp[1], x[1]);
            }
            else {
                ans.push_back(temp);
                temp = x;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};