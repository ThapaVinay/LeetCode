class Solution {
public:
    
    bool checkBit(int n, int i)
    {
        n = n >> i;
        if(n%2 ==0)
            return false;
        else 
            return true;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        
        int total = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            total  = total ^ nums[i];
        }
        
        int id = -1;
        for(int i=0; i<32; i++)
        {
            if(checkBit(total, i) == true)
            {
                id = i;
                break;
            }
        }
        
        int first = 0;
        int second = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(checkBit(nums[i], id) == true)
            {
                first = first ^ nums[i];
            }
            else{
                second = second ^ nums[i];
            }
        }
        
        return {first, second};
        
    }
};