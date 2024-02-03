class Solution {
public:
    string simplifyPath(string path) {
        
        // split the path at "/" and store it in array
        vector <string> arr;
        string temp = "";
        for(int i=0; i<path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(temp.size())
                    arr.push_back(temp);
                temp = "";
            }
            else
                temp += path[i];
        }
        if(temp.size())
            arr.push_back(temp);
        
        
        // now check the conditions
        stack <string> st;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == "..")
            {
                if(!st.empty())
                    st.pop();
            }    
            else if(arr[i] == ".")
                continue;
            else
                st.push(arr[i]);
        }
        
        if(st.empty())
            return "/";
        
        // now add the stack values to res
        string res = "";
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};