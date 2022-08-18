class Solution {
public:
//     int solve(int idx, int prev, vector<int> &nums, int n, vector<vector<int>> &t) {
//         if(idx==n) {
//             return 0;
//         }
        
//         if(t[idx][prev+1]!=-1) return t[idx][prev+1];
        
//         int len=0+solve(idx+1,prev,nums,n,t);
//         if(prev==-1 || nums[idx]>nums[prev]) {
//             len=max(len,1+solve(idx+1,idx,nums,n,t));
//         }
        
//         return t[idx][prev+1]=len;
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
//         vector<vector<int>> t(n+1, vector<int>(n+1,-1));
        
//         return solve(0,-1,nums,n,t);
       
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
        for(int idx=n-1;idx>=0;idx--) {
            for(int prev=idx-1;prev>=-1;prev--) {
                int len=0+t[idx+1][prev+1];
                if(prev==-1 || nums[prev]<nums[idx]) {
                    len=max(len,1+t[idx+1][idx+1]);
                }
                t[idx][prev+1]=len;
            }
        }
        
        return t[0][-1+1];
    }
};