class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method 1: Sorting
        sort(nums.begin(), nums.end());

        // Methode 2: Count Sort
        int count0, count1, count2;
        count0 = count1 = count2 = 0;
        for (auto x : nums) {
            if (!x) count0++;
            else if (x == 1) count1++;
            else count2++;
        }

        int i = 0;
        while (count0--) {
            nums[i++] = 0;
        }
        while (count1--) {
            nums[i++] = 1;
        }
        while (count2--) {
            nums[i++] = 2;
        }

        // Method 3: DNF
        int low, mid, high;
        low = mid = 0;
        high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
            else {
                mid++;
            }
        }
    }
};