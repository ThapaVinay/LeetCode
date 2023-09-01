class Solution {
public:
    
    int countDP(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        
        int a;
        if(n % 2 == 1)
            a = 1 + countDP(n/2);
        
        else if(n % 2 == 0)
            a = countDP(n/2);
        
        return a;
            
        
    }
    
    
    vector<int> countBits(int n) {
        
        vector <int> res(n+1);
        res[0] = 0;
        for(int i=1; i<=n; i++)
        {
            res[i] = countDP(i);
        }
        return res;
    }
};