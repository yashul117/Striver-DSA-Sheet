class Solution {
public:
    int romanToInt(string s) {
       int ans=0;
        
        unordered_map<char,int> roman;
        
        roman.insert(pair<char,int>('I',1));
        roman.insert(pair<char,int>('V',5));
        roman.insert(pair<char,int>('X',10));
        roman.insert(pair<char,int>('L',50));
        roman.insert(pair<char,int>('C',100));
        roman.insert(pair<char,int>('D',500));
        roman.insert(pair<char,int>('M',1000));
        
        for(int i=0;i<s.length();i++) {
            if(roman[s[i]]>=roman[s[i+1]])
                ans+=roman[s[i]];
            else
                ans-=roman[s[i]];
        }
        
        return ans;
    }
};