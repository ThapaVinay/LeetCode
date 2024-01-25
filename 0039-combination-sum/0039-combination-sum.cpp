class Solution {
public:
    
    set <vector<int>> res;
    
    void recur(vector<int> &candidates, int target, vector<int> &temp)
    {
        if(target == 0)
        {
            vector <int> clone(temp);
            
            sort(clone.begin(), clone.end());
            
            if(res.find(clone) != res.end())
                return;
            
            res.insert(clone);
            return;
        }
        
        if(target < 0)
            return;
        
        for(auto x: candidates)
        {
            temp.push_back(x);
            recur(candidates, target - x, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector <int> temp;
        
        recur(candidates, target, temp);
        
        vector <vector<int>> ans;
        
        for(auto x: res)
            ans.push_back(x);
        
        return ans;
    }
};