class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = nums[0];
        int local = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            local += nums[i];
            
            maxi = max(local, maxi);
            
            if(local < 0){
                local = 0;
            }
        }
        
        return maxi;
    }
};