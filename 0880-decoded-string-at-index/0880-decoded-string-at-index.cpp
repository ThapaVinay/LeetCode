class Solution {
public:
    
    string decodeAtIndex(string s, int k) {
        
        long long size = 0;
        for(auto &ch: s)
        {
            if(ch >= '0' && ch <= '9')
            {
                size *= (ch-'0');
            }
            else{
                size += 1;
            }
        }
        
        for(int i=s.size()-1; i>=0; i--)
        {
            char ch = s[i];
            k = k%size;
            if(k == 0 && ch >= 'a' && ch <= 'z')
            {
                return string("") + ch;
            }
            else if(ch >= 'a' && ch <= 'z'){
                size--;
            }
            else{
                size /= ch-'0';
            }
            
        }
        
        
        return "";
        
    }
};