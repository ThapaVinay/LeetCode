class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int countOne = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '1')
                countOne ++;
        }
        
        string res = "";
        countOne --;
        for(int i=0; i<s.size()-1; i++)
        {
            if(countOne)
            {
                res += '1';
                countOne --;
            }
            else{
                res += '0';
            }
        }
        res += '1';
        
        return res;
    }
};