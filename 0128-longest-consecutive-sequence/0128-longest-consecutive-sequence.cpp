class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int maxi = 1;
        int curr = 1;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
                continue;
            
            if(nums[i] == nums[i+1] - 1)
            {
                curr ++;
            }
            else{
                maxi = max(curr, maxi);
                curr = 1;
            }
            
        }
        
        maxi = max(curr, maxi);
        
        return maxi;
    }
};