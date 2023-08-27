class Solution {
public:
    
    bool crossDP( vector<int> &stones, int value, int k, unordered_map<int, unordered_set<int>> &dp)
    {
        if(value == stones.back())
        {
            return true;
        }
        
        if(!binary_search(stones.begin(), stones.end(), value) || k == 0)
        {
            return false;
        }

        if (dp.count(value) && dp[value].count(k)) {
            return false;
        }
        
        if(crossDP(stones, value+k-1, k-1, dp) || crossDP(stones, value+k+1, k+1,dp) || crossDP(stones, value+k, k, dp)){
            return true;
        }
        
        dp[value].insert(k);
        return false;
        
    }
    
    bool canCross(vector<int>& stones) {
        
        unordered_map<int, unordered_set<int>> dp;
        return crossDP(stones, 1, 1, dp);
    }
};