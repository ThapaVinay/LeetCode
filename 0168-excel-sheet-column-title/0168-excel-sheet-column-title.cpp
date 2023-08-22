class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s = "";
        while(columnNumber > 0)
        {
            int a = columnNumber % 26;
            
            if(a == 0)
                a = 26;
            s += (char)(a+64);
            
            columnNumber -= a;
            columnNumber  = columnNumber/26;
            
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};