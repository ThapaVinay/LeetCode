class Solution {
public:
    
    void permuteRec(int n, vector<vector<int>> &ans, vector <int> &curr, int k)
    {
        if(curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }
        
        if(ans.size() == k)
            return;
        
        for(int i=1; i<=n; i++)
        {
            if(find(curr.begin(), curr.end(), i) == curr.end())
            {
                curr.push_back(i);
                permuteRec(n, ans, curr, k);
                curr.pop_back();
            }
        }
        
    }
    
    string getPermutation(int n, int k) 
    {
        vector <vector<int>> ans;
        vector <int> curr;
        
        permuteRec(n, ans, curr, k);
        
        string s = "";
        for(auto ch: ans[k-1])
        {
            s += ch + '0';
        }
        
        return s;
    }
};