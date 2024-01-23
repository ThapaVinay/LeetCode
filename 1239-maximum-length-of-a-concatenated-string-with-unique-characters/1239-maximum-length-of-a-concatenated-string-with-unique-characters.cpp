class Solution {
public:
    
    bool check (string &s) 
    {
        unordered_set <char> mp;
        
        for(int i=0; i<s.size() ;i++) 
        {
            if(mp.count(s[i]) == 1) 
                return false;
            
            mp.insert(s[i]);
        }
        
        return true;
    }
    
    int recurDP(vector<string> &arr, string &s, int i) 
    {
        if(i >= arr.size())
        {
            return s.size();
        }
        
        
        // take 
        int take = 0, not_take = 0;
        string temp = s + arr[i];
        if(check(temp))
        {
            s += arr[i];
            take = recurDP(arr, s, i+1);
            s = s.substr(0, s.size() - arr[i].size());
            not_take = recurDP(arr, s, i+1);
        }
        else{
            // not take
            not_take = recurDP(arr, s, i+1);
        }
        
        return max(take, not_take);
        
    }            
    
    int maxLength(vector<string>& arr) {
        
        string temp = "";
        
        // vector <vector<int>> dp(20, vector<int>(500, -1));
        
        return recurDP(arr, temp, 0);
    }
};