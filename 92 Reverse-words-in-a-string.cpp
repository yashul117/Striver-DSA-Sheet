class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        
        for(int i=0;i<s.length();i++) {
            if(s[i]!=' ') {
                temp.push_back(s[i]);
            }
            else if(temp.length()>0){
                st.push(temp);
                temp.erase(temp.begin(),temp.begin()+temp.length());
            }
        }
        
        if(temp.length()>0)
            st.push(temp);

        string ans;
        
        while(!st.empty()) {
            ans+=st.top();
            ans+=' ';
            st.pop();
        }
        ans.erase(ans.end()-1,ans.end());
        return ans;
    }
};