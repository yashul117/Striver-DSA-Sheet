class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         vector<int> ans;
//         for(auto it:nums) {
//             mp[it]++;
//         }

//         unordered_map<int,int>::iterator it;

//         for(it=mp.begin();it!=mp.end();it++) {
//             if(it->second>nums.size()/3) {
//                 ans.push_back(it->first);
//             }
//         }

//         return ans;

        // Extended Boyer Moore’s Voting Algorithm:
        // Intuition: There can only be a max of 2 majority elements in the array.

        int num1, num2, c1, c2;
        vector<int> ans;
        num1 = num2 = -1;
        c1 = c2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1) {
                c1++;
            }
            else if (nums[i] == num2) {
                c2++;
            }
            else if (c1 == 0) {
                num1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0) {
                num2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1)
                c1++;
            else if (nums[i] == num2)
                c2++;
        }

        if (c1 > nums.size() / 3)
            ans.push_back(num1);
        if (c2 > nums.size() / 3)
            ans.push_back(num2);

        return ans;

    }
};