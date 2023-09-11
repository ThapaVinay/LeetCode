class Solution {
public:
    string removeStars(string s) {
        
        vector <char> arr;
        for(auto ch: s)
        {
            if(ch == '*')
            {
                arr.pop_back();
            }
            else{
                arr.push_back(ch);
            }
        }
        
        string res = "";
        for(auto ch: arr)
        {
            res += ch;
        }
        
        return res;
    }
};