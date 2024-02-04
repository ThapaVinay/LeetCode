class Solution {
public:
    
    void recur(vector<int>& nums, vector<vector<int>> &res, vector<int>& temp, int i)
    {
        if(i == nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        // take
        temp.push_back(nums[i]);
        recur(nums, res, temp, i+1);
        temp.pop_back();
        
        // not_take
        recur(nums, res, temp, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        
        recur(nums, res, temp, 0);
        
        return res;
    }
};