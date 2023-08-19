class Solution {
public:
    
    int sideDP(vector<int> &obstacles, int lane, int point, vector <vector<int>> &dp)
    {
        int n = obstacles.size();
        
        if(point == n-1)
        {
            return 0;
        }
        
        if(dp[lane][point] != -1)
        {
            return dp[lane][point];
        }
        
        if(obstacles[point+1] != lane)
        {
            return sideDP(obstacles, lane, point+1, dp);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++)
            {
                if( lane != i && obstacles[point] != i )
                {
                    ans = min(1 + sideDP(obstacles, i, point, dp), ans);
                }
            }
            dp[lane][point] = ans;
            return ans;
        }
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        vector <vector<int>> dp(4, vector<int>(obstacles.size()+1,-1));
        // frog at one lane has two options
        
        // starts from second lane
        return sideDP(obstacles, 2, 0, dp);
    }
};