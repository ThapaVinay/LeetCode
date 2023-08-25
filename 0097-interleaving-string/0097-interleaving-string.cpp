class Solution {
public:
    
    bool interRec(string s1, string s2, string s3, int i, int j, int k, unordered_map<string, bool> &dp)
    {
        // base
        if (k == s3.size() && i == s1.size() && j == s2.size())
        {
            return true;
        }
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(k);
        
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        if(s1[i] == s3[k] && s2[j] == s3[k])
        {
            return dp[key] = interRec(s1, s2, s3, i+1, j, k+1, dp) || interRec(s1, s2, s3, i, j+1, k+1, dp);
            
        }
        else if(s1[i] == s3[k])
        {
            return dp[key] = interRec(s1, s2, s3, i+1, j, k+1, dp);
        }
        else if(s2[j] == s3[k])
        {
            return dp[key]  = interRec(s1, s2, s3, i, j+1, k+1, dp);
        }
            
        else{
            return dp[key] = false;
        }
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if((s1.size() + s2.size()) != s3.size())
            return false;
        
        unordered_map<string, bool> dp;
        return interRec(s1, s2, s3, 0, 0, 0, dp);
        
        
    }
};