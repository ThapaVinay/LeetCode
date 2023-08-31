class Solution {
public:
    
    void recursionSum(vector<int> &candidates, int target, int index, vector <int> &temp, vector <vector<int>> &res)
    {
    
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        
        if(target < 0 || index > candidates.size())
        {
            return;
        }
        
        
        for(int i=index; i<candidates.size(); i++)
        {
            
            if(i>index && candidates[i]  == candidates[i-1])
                continue;
            
            temp.push_back(candidates[i]);
            recursionSum(candidates, target-candidates[i], i+1,temp,res);
            temp.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector <int> temp;
        vector <vector<int>> res;
        sort(candidates.begin(), candidates.end());
        recursionSum(candidates, target, 0, temp, res);
        return res;
    }
};