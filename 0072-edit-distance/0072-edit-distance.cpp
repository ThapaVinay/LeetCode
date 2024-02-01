class Solution {
public:
    
    int recurDP(string &word1, string &word2, int i, int j, vector<vector<int>>& dp)
    {
        // if word1 is smaller than word2
        if(i >= word1.size())
            return word2.size() - j;
        
        // if word2 is smaller than word1
        if(j >= word2.size())
            return word1.size() - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        if(word1[i] == word2[j])
        {
            res = recurDP(word1, word2, i+1, j+1, dp);
        }
        else{
            // replace
            int temp1 = 1 + recurDP(word1, word2, i+1, j+1, dp);
            
            // delete
            int temp2 = 1 + recurDP(word1, word2, i+1, j, dp);
            
            // insert
            int temp3 = 1 + recurDP(word1, word2, i, j+1, dp); 
            
            res = min(temp1, min(temp2, temp3));
        }
        
        return dp[i][j] = res;
    }
    
    int minDistance(string word1, string word2) {
        
        // we will have three options whether to 
        // -> insert (i, j+1), delete (i+1, j) or replace (i+1, j+1).
        
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return recurDP(word1, word2, 0, 0, dp);
    }
};