class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector <int> res;
        int n = digits.size();
        
        int carry = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            int val = 0;
            if(i == n-1)
                val = 1 + digits[i] + carry;
            else
                val = carry + digits[i];
            
            if(val > 9)
            {
                carry = val / 10;
                val = val % 10;
            }
            else
                carry = 0;
            
            res.push_back(val);
        }
        
        if(carry)
            res.push_back(carry);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};