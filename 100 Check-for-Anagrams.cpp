class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        
        for(int i=0;i<s.length();i++) {
            hash[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++) {
            hash[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++) {
            if(hash[i]!=0)
                return false;
        }
        
        return true;
    }
};