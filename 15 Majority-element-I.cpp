class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*        unordered_map<int,int> mp;

                for(auto it:nums) {
                    mp[it]++;
                }

                unordered_map<int,int>::iterator it;

                for(it=mp.begin();it!=mp.end();it++) {
                    if(it->second>nums.size()/2) {
                        return it->first;
                    }
                }

                return -1;*/

        // Moore's Voting Algo:
        // Premise: There is a majority element present in the array.

        int count, ele;
        count = 0;
        ele = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                ele = nums[i];
            }

            if (ele == nums[i]) {
                count++;
            }
            else {
                count--;
            }
        }

        return ele;
    }
};