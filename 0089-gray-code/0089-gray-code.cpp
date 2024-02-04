class Solution {
public:
    
    vector<string> recur(int n)
    {
        // base case
        if(n == 1)
            return {"0", "1"};
        
        vector <string> temp = recur(n-1);
        
        vector <string> ans;
        
        // add '0' to the strings
        for(int i=0; i<temp.size(); i++)
        {
            ans.push_back('0' + temp[i]);
        }
        
        // add '1' to strings from back
        for(int i=temp.size()-1; i>=0; i--)
        {
            ans.push_back('1' + temp[i]);
        }
        
        return ans;
    }
    
    vector<int> grayCode(int n) {
        
        // for finding the gray code for 3.
        // 1. first find the gray code for 2
        // 2. then add 0 to each binary value
        // 3. then add 1 to each after reversing it from back
        
        vector <string> grayString = recur(n);
        
        vector <int> res;
        for(auto x: grayString)
        {
            // to convert binary to integer
            res.push_back(stoi(x, 0 ,2));
        }
        
        return res;
    }
};


