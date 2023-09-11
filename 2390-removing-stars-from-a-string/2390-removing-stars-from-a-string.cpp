class Solution {
public:
    string removeStars(string s) {
        stack <int> st;
        
        for(auto ch: s)
        {
            if(ch == '*')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};