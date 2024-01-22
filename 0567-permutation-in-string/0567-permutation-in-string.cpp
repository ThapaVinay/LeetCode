class Solution {
public:
    
    bool equal(int a[], int b[])
    {
        for(int i=0; i<26; i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool checkInclusion(string s1, string s2) {
        
        // just store all the characters of the string s1 in array and using sliding window
        
        if(s2.size() < s1.size())
        {
            return false;
        }
        
        int a[26] = {0}, b[26] = {0};
        
        for(int i=0; i<s1.size(); i++)
        {
            char ch = s1[i];
            a[ch-'a'] ++;
        }
        
        // make the window
        int i = 0, j = 0;
        while(i < s1.size())
        {
            char ch = s2[i++];
            b[ch-'a'] ++;
        }
        
        // check if equal
        if(equal(a,b))
        {
            return true;
        }
        
        // now go for the next windows
        while(i < s2.size())
        {
            char ch1 = s2[j++];
            char ch2 = s2[i++];
            
            b[ch1-'a'] --;
            b[ch2-'a'] ++;
            
            if(equal(a,b))
            {
                return true;
            }
        }
        
        return false;
    }
};