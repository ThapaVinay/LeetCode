class Solution {
public:
    
    bool find132pattern(vector<int>& nums) {
        
        stack <pair<int,int>> s;
        int mini = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            while(!s.empty() && s.top().first <= nums[i])
            {
                s.pop();
            }

            if(!s.empty() && s.top().second < nums[i])
                return true;

            s.push({nums[i], mini});
            mini = min(mini, nums[i]);
            
        }
        return false;

    }
};