class Solution {
public:
    string reverseWords(string s) {
        
        int r=0;
        for(int i=0; i<=s.size(); i++)
        {
            if(s[i] == ' ' || i == s.size())
            {
                reverse(s.begin() + r, s.begin() + i);
                r = i+1;
            }
        }
        return s;
    }
};