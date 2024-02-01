class Solution {
public:
    bool isNumber(string s) {
        
        int i = 0;
        int n = s.size();
        
        // checking the sign
        if(s[i] == '+' || s[i] == '-')
            i++;    
        
        if(i == n) return false;
        
        bool numbers = false;
        // checking for numbers before dot
        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            numbers = true;
            i++;
        }
        
        if(i == n) return true;
        
        // checking for dot
        bool dot = false;
        if(s[i] == '.')
        {
            dot = true;
            i++;
        }
        
        // will return false if there is only dot without preceding numbers
        if(i == n)
        {
            if(dot && !numbers) return false;
            else return true;
        }
        
        // check for numbers after dot
        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            numbers = true;
             i++;
        }   
        
        if(i == n) return true;
        
        bool checke = false;
        // checking for e
        if(numbers && (s[i] == 'e' || s[i] == 'E'))
        {
            checke = true;
            i++;
        }
        
        if(i == n) return false;
        
        // checking for sign
        if(checke && (s[i] == '+' || s[i] == '-'))
            i++;
        
        if(i == n) return false;
        
        // checking for numbers
        while(i < n && s[i] >= '0' && s[i] <= '9')
            i++;
        
        if(i == n) return true;
        
        cout << i;
        
        return false;
    }
};