class Solution {
public:
    int lengthOfLastWord(string s) {
        // we will count the words from start
        // and when space encounters reset count and add to res
        
        int res = 0;
        int count = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != ' ')
            {
                count ++;
            }
            else if(count != 0)
            {
                res = count;
                count = 0;
            }
            else{
                count = 0;
            }
        }
        if(count)
        {
            res = count;
        }
        return res;
    }
};