class Solution {
public:
    
    void permuteRec(vector <int> &nums, vector<vector<int>> &ans, vector <int> &curr)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        
        
        for(int n : nums)
        {
            if(find(curr.begin(), curr.end(), n) == curr.end())
            {
                curr.push_back(n);
                permuteRec(nums, ans, curr);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector <vector<int>> ans;
        vector <int> curr;
        permuteRec(nums,ans, curr);
        return ans;
    }
};