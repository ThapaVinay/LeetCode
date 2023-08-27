class Solution {
public:
    
    static bool isValid(string s)
    {
        if(s.size() == 1)
            return true;
        
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i] != s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }

    
    void partDP(string s, int i, vector<string> &temp, vector <vector<string>> &res)
    {
        if(i == s.size())
        {
            res.push_back(temp);
            return;
        }
        
        
        for(int index = i; index<s.size(); index++)
        {
            if(isValid(s.substr(i,index-i+1)))
            {
                temp.push_back(s.substr(i, index-i+1));
                partDP(s, index+1, temp, res);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        
        vector <string> temp;
        
        partDP(s, 0, temp, res);
        
        return res;
    }
};