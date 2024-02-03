class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0)
            return 0;
        
        int res = 1;
        for(int i=2; i<x && i <= INT_MAX/i; i++)
        {
            if(i*i == x)
            {
                return i;
            }
            else if(i*i > x)
                return res;
            
            res = i;
        }
        
        return res;
    }
};