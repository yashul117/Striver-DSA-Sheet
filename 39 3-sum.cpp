class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.size() < 2)
            return res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {

            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int high = nums.size() - 1;
                int sum = 0 - nums[i];

                while (lo < high) {
                    if (sum == nums[lo] + nums[high]) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        while (lo < high && nums[lo + 1] == nums[lo]) lo++;
                        while (lo < high && nums[high - 1] == nums[high]) high--;

                        lo++;
                        high--;
                    }
                    else if (nums[lo] + nums[high] < sum) lo++;
                    else high--;
                }
            }
        }
        return res;
    }
};