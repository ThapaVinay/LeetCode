class Solution {
public:
    
    void recur(vector<int>& nums, set<vector<int>> &res, vector<int>& temp, int i)
    {
        if(i == nums.size())
        {
            res.insert(temp);
            return;
        }
        
        // take
        temp.push_back(nums[i]);
        recur(nums, res, temp, i+1);
        temp.pop_back();
        
        // not_take
        recur(nums, res, temp, i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> res;
        vector<int> temp;
        
        recur(nums, res, temp, 0);
        
        vector <vector<int>> ans;
        
        for(auto x: res)
        {
            ans.push_back(x);
        }
        
        return ans;
    }
};