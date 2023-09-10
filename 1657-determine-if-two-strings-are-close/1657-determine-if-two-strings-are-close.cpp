class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        // first we will insert all the values in two maps
        // then check if more than two numbers differ
        
        if(word1.size() != word2.size())
        {
            return false;
        }
        
        vector <int> mp1 (26);
        vector <int> mp2 (26);
        set <char> st1;
        set <char> st2;
        
        for(int i=0; i<word1.size(); i++)
        {
            mp1[word1[i] - 'a']++;
            mp2[word2[i] - 'a']++;
            st1.insert(word1[i]);
            st2.insert(word2[i]);
        }
        
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        
        if(st1 != st2)
            return false;
        
        for(int i=0; i<mp1.size(); i++)
        {
            if(mp1[i] != mp2[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
};