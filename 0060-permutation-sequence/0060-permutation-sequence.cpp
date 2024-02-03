class Solution {
public:
    
    void permuteRec(vector <int> &nums, vector<vector<int>> &ans, vector <int> &curr, int k)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        
        if(ans.size() == k)
            return;
        
        for(int n : nums)
        {
            if(find(curr.begin(), curr.end(), n) == curr.end())
            {
                curr.push_back(n);
                permuteRec(nums, ans, curr, k);
                curr.pop_back();
            }
        }
        
    }
    
    string getPermutation(int n, int k) 
    {
        vector <vector<int>> ans;
        vector <int> curr;
        vector <int> nums;
        
        for(int i=0; i<n; i++)
        {
            nums.push_back(i+1);
        }
        
        permuteRec(nums,ans, curr, k);
        
        string s = "";
        for(auto ch: ans[k-1])
        {
            s += ch + '0';
        }
        
        return s;
    }
};