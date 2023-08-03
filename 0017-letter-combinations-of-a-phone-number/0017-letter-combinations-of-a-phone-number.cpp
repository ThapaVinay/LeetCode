class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector <string> map  = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector <string> res;
        
        if(digits.size() == 0)
        {
            return res;
        }
        
        res.push_back("");
        
        for(auto digit : digits)
        {
            string value = map[digit- '0'];
            vector <string> temp;
            for(auto ch : value)
            {
                for(auto s : res)
                {
                    temp.push_back(s + ch);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};