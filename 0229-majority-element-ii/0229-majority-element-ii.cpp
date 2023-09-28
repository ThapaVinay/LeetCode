class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // if(nums.size() == )
        
        sort(begin(nums), end(nums));
        vector <int> res;
        
        int count = 0;
        int prev = nums[0];
        int majority = nums.size()/3;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(prev == nums[i])
            {
                count ++;
            }
            else{
                prev = nums[i];
                count = 1;
            }
            
            if(count == majority+1)
            {
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};