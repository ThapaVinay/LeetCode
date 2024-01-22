class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        for(int i=0; i<=s.size(); i++)
        {
            for(int j=i; j+part.size()<=s.size(); j++)
            {
                string word = s.substr(j, part.size());
                if(part == word)
                {
                    s.erase(j, part.size());
                    i--;
                    break;
                }
            }
            
        }
        
        return s;
    }
};