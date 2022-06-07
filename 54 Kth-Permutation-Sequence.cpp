class Solution {
public:
    int factorial(int n) {
        if (n > 1)
            return n * factorial(n - 1);
        else
            return 1;
    }

    string getPermutation(int n, int k) {
        int fact = factorial(n - 1);
        string ans = "";
        string nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back('0' + i);
        }

        k--;
        while (n >= 1) {
            int fact = factorial(n - 1);
            int idx = k / fact;
            ans.push_back(nums[idx]);
            nums.erase(nums.begin() + idx);
            k = k % fact;
            n--;
        }

        return ans;
    }
};