class Solution {
public:
    string removeDuplicates(string s) {
        
        string st = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(st.size() > 0 && st.back() == s[i])
            {
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        
        return st;
    }
};