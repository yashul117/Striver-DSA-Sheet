class Solution {
public:
    bool check(string a, string b) {
        int n=a.size();
        int m=b.size();
        
        for(int i=0;i<=n-m;i++) {
            int j;
            for(j=0;j<m;j++) {
                if(a[i+j]!=b[j]) {
                    break;
                }
            }
            if(j==m) {
                return true;
            }
        }
        
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        
        int ans=1;
        
        string temp=a;
        while(a.size()<m) {
            a=a+temp;
            ans++;
        }
        
        if(check(a,b)) {
            return ans;
        }
        
        if(check(a+temp,b)) {
            return ans+1;
        }
        
        return -1;
    }
};