class Solution {
public:
    int titleToNumber(string c) {
        int n = 0;
        int power = 1;  
        
        for (int i = c.size() - 1; i >= 0; i--) {
            char ch = c[i];
            int val = (int)ch - 'A' + 1;  
            n += val * power;
            if(i != 0)
                power *= 26;
        }
        
        return n;
    }
};
