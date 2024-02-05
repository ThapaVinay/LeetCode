class Solution {
public:
    
    void recur(string s, vector<string> &res, vector<string> &temp, int i)
    {
        if(i == s.size())
        {
            if(temp.size() == 4)
            {
                string s = "";
                for(int j=0; j<4; j++)
                {
                    s += temp[j];
                    if(j < 3)
                        s += '.';
                }
                res.push_back(s);
            }
            return;
        }
        
        if(temp.size() >= 4)
            return;
        
        // one character
        temp.push_back(s.substr(i, 1));
        recur(s, res, temp, i+1);
        temp.pop_back();
        
        // two characters
        if(i+1 < s.size() && s[i] != '0')
        {
            temp.push_back(s.substr(i, 2));
            recur(s, res, temp, i+2);
            temp.pop_back();
        }
        
        // three characters
        if(i+2 < s.size() && s[i] != '0' && s[i] <= '2')
        {
            string temp1 = s.substr(i, 3);
            
            if(stoi(temp1) > 255)
                return;
            
            temp.push_back(temp1);
            recur(s, res, temp, i+3);
            temp.pop_back();
        }
    }
        
    vector<string> restoreIpAddresses(string s) {
        
         // we can either select one, two or three characters
        
        int n = s.size();
        vector<string> res;
        vector<string> temp;
        
        recur(s, res, temp, 0);
        return res;
    }
};