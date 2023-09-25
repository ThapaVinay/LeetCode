class Solution {
public:
    
    double dp[101][101];
    double champagneDP(double p, int i, int j)
    {
        if(i<0 || j<0 || i<j)
        {
            return 0.0;
        }
        
        if(i ==0 && j ==0)
            return p;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        double left = (champagneDP(p, i-1, j-1)-1)/2.0;
        
        double right = (champagneDP(p, i-1, j)-1)/2.0;
            
        if(left < 0)
            left = 0.0;
        
        if(right < 0)
            right = 0.0;
        
        return dp[i][j] = left + right;
        
    }
    
    
    double champagneTower(int p, int qr, int qg) {
        
        for(int i=0; i<101; i++)
        {
            for(int j=0; j<101; j++)
                dp[i][j] = -1;
        }
        return min(1.0, champagneDP(p, qr , qg));

    }
};