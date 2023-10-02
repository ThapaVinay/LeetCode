class Solution {
public:
    
    bool checkBit(int n, int i)
    {
        n = n >> i;
        if(n % 2 == 0)
        {
            return false;
        }
        else{
            return true;
        }
        
    }
    
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
        
        // iterate for every bit
        for(int i=0; i<32; i++)
        {
            int count = 0;
            
            // count no. of ones and zeroes at each bit
            for(int j=0; j<nums.size(); j++)
            {
                // counting ones
                if(checkBit(nums[j], i) == true)
                    count ++;
            }
            
            if(count % 3 != 0)
                res = res + (1 << i);
        }
        
        return res;
        
    }
    
};