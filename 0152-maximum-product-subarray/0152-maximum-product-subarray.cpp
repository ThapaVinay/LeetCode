class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // we are trying to remove one minus digit in case of odd negative numbers
        
        int maxi = nums[0];
        int local = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            local *= nums[i];
            maxi = max(local, maxi);
            
            if(local == 0)
                local = 1;
        }
        
        local = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            local *= nums[i];
            maxi = max(local, maxi);
            
            if(local == 0)
                local = 1;
        }
        
        return maxi;
    }
};