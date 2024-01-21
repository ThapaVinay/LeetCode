class Solution {
public:
    int myAtoi(string s) {
        
        if(s.size() == 0)
            return 0;
        
        int i =0, sign = 1;
        
        // remove whitespaces
        while(i < s.size() && s[i] == ' ')
            i++;
        
        // check for sign
        if(s[i] == '+' || s[i] == '-')
        {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        
        long res = 0;
        // check for digits
        while(i < s.size())
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                res = res*10 + (s[i] - '0');
            }
            else{
                return res * sign;
            }
            
            if(res > INT_MAX)
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            
            i++;
            
        }
        
        return res * sign;
    }
};