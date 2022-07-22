class Solution {
public:
    void constructLPS(vector<int> &lps, string s, int sz) {
        int len=0,i=1;
        lps[0]=0;
        
        while(i<sz) {
            if(s[i]==s[len]) {
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len!=0) {
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        
        vector<int> lps(n);
        
        constructLPS(lps,needle,n);
        
        int j=0;
        for(int i=0;i<m;) {
            if(haystack[i]==needle[j]) {
                j++;
                i++;
                if(j==n) {
                    return (i-n);
                }
            }
            else {
                if(j) {
                    j=lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        
        return -1;
    }
};