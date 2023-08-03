class Solution {
public:
    
    void backtrack(int n, int k, vector <vector<int>> &res, vector <int> &temp)
    {
        if(temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        
        int start = temp.empty() ? 1 : temp.back() + 1;
        for(int i=start; i<=n; i++)
        {
            
            temp.push_back(i);
            backtrack(n,k, res,temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector <vector<int>> res;
        vector <int> temp;
        
        backtrack(n,k, res, temp);
        return res;
    }
};