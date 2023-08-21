class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        
        for(int i=1; i<=n/2; i++)
        {
            
            if(n%i != 0)
            {
                continue;
            }
            
            string temp = s.substr(0,i);
            
            int times = n/temp.size();
            
            string value = "";
            for(int j=0; j<times; j++)
            {
                value += temp;
            }
            
            if(value.compare(s) == 0)
            {
                return true;
            }
            
        }
        return false;
    }
};