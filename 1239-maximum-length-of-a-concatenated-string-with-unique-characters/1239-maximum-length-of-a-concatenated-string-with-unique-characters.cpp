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
    
    int recurDP(vector<string> &arr, string &s, int i, unordered_map <string, int> &mp) 
    {
        if(i >= arr.size())
        {
            return s.size();
        }
        
        if(mp[s])
            return mp[s];
        
        // take 
        int take = 0, not_take = 0;
        string temp = s + arr[i];
        if(check(temp))
        {
            s += arr[i];
            take = recurDP(arr, s, i+1, mp);
            s = s.substr(0, s.size() - arr[i].size());
            not_take = recurDP(arr, s, i+1, mp);
        }
        else{
            // not take
            not_take = recurDP(arr, s, i+1, mp);
        }
        
        return mp[s] = max(take, not_take);
        
    }            
    
    int maxLength(vector<string>& arr) {
        
        string temp = "";
        unordered_map <string, int> mp;
        
        return recurDP(arr, temp, 0, mp);
    }
};