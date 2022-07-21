//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void constructLPS(string s, vector<int> &lps) {
        int i=1,len=0;
        lps[0]=0;
        
        while(i<s.length()) {
            if(s[len]==s[i]) {
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
    
    int minChar(string str){
        //Write your code here
        string rev=str;
        reverse(rev.begin(),rev.end());
        
        string concat=str+'$'+rev;
        
        vector<int> lps(concat.length(),0);
        constructLPS(concat,lps);
        
        return str.length()-lps.back();


        // Optimal Solution: 2-pointer approach
/*        int n = str.length();
	    int left = 0;
	    int right = n - 1;
	    int added = 0;
	    while (left < right) {
	        // if left and right characters are same increase
	        // left and decrease right pointer
	        if (str[left] == str[right]) {
	            left++;
	            right--;
	        }
	        // else think of adding some characters at front and
	        // start comparing the elements again
	        else {
	            left = 0;
	            added = n - right;
	            if (str[left] == str[right]) {
	                added--;
	                left++;
	            }
	            right--;
	        }
	    }
	    return added;*/
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends