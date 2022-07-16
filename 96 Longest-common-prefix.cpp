class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        string ans="";
        
        int n=strs.size();
        for(int j=0;j<strs[0].size();j++) {
            for(int i=1;i<n;i++) {
                if(strs[i][j]!=strs[i-1][j])
                    return ans;
            }
            ans.push_back(strs[0][j]);
        }
        
        return ans;
    }
};