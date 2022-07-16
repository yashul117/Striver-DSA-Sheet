class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        long i = 0, res = 0;
        
        while(s[i] == ' ')
            i++;
        
        if(i == s.size()) return 0;
        
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-'){
                neg = true;
            }
            i++;
        }
        
        else if(!isdigit(s[i]))
            return 0;
        
        while(isdigit(s[i])){
            res = res * 10 + (s[i]-'0');
            if(res > INT_MAX){
                if(neg) return INT_MIN;
                return INT_MAX;
            }
            i++;
        }
        
        return (neg) ? -res : res;
    }
};