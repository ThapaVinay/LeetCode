class Solution {
public:
    
    unordered_set <string> res;
    
    bool check(string &s)
    {
        stack <char> st;
        
        for(auto &ch: s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else if(st.top() == '(' && ch == ')')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
        return st.size() == 0;
    }
    
    void recur(int n, string &s)
    {
        if(s.size() >= n)
        {
            if(check(s))
            {
                res.insert(s);
                return;
            }
            return;
        }
        
        // adding '('
        s.push_back('(');
        recur(n, s);
        s.pop_back();
        
        // adding ')'
        if(s.size() != 0) 
        {
            s.push_back(')');
            recur(n, s);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string temp = "";
        recur(2*n, temp);
        
        vector <string> ans;
        for(auto &x: res)
            ans.push_back(x);
        
        return ans;
        
    }
};