class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        
        vector<vector<int>> res;
        
        if(nums[0]  > 0)
            return res;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int l = i+1;
            int r = n-1;
            
            while(l<r)
            {
                
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[l] == nums[r+1]) r--;
                }
                else if(sum < 0)
                {
                    l++;
                    
                }
                else{
                    r--;
                }
            }
        }
        
        return res;
    }
};