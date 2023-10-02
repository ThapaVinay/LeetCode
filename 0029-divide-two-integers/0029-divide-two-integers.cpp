class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long res = (long)dividend/(long)divisor;
        
        if(res >= INT_MAX)
        {
            return INT_MAX;
        }
        
        if(res <= INT_MIN)
        {
            return INT_MIN;
        }
        
        return res;
    }
};