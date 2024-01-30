class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack <string> st;
        
        for(int i=0; i<tokens.size(); i++)
        {
            string s = tokens[i];
            
            if(s != "+" && s != "*" && s != "/" && s != "-")
            {
                st.push(s);
            }
            else{
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                                
                int res = 0;
                
                if(s == "*")
                    res = b * a;
                else if(s == "/")
                    res = b / a;
                else if(s == "-")
                    res = b - a;
                else if(s == "+")
                    res = b + a;
                
                st.push(to_string(res));   
            }
        }
        
        cout << st.top();
        return stoi(st.top());
    }
};