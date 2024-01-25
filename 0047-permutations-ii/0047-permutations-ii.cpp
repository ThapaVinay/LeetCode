class Solution {
public:
    
    set <vector<int>> res;
    
    void recur(vector <int> &nums, vector <int> &temp, vector <int> &index)
    {
        if(temp.size() == nums.size())
        {
            if(res.count(temp))
                return;
            
            res.insert(temp); 
            return;
        }
        
        
        for(int i=0; i<nums.size(); i++)
        {
            if(find(index.begin(), index.end(), i) != index.end())
                continue;
            
            index.push_back(i);
            temp.push_back(nums[i]);
            
            recur(nums, temp, index);
            
            temp.pop_back();
            index.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector <int> temp;
        vector <int> index;
        
        sort(nums.begin(), nums.end());
        
        recur(nums, temp, index);
        
        vector <vector<int>> ans;
        
        for(auto x: res)
        {
            ans.push_back(x);
        }
        
        return ans;
    }
};