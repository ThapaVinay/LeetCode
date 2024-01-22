class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        // first save the words in a map
        // then at each character in s check if the word is present in the map
        
        unordered_map <string, int> mp, temp;
        
        // saving the words in map
        for(string word: words)
        {
            mp[word] ++;
        }
        
        // check for overflow
        int size = s.size() - words.size() * words[0].size();
        int word_size = words[0].size(); 
        
        vector <int> ans;
        
        for(int i=0; i<=size; i++)
        {
            int total_words = 0;
            // make words and compare
            
            for(auto pair: mp)
            {
                temp[pair.first] = pair.second;
            }
            
            for(int j=i; j<s.size(); j=j+word_size)
            {
                string word = s.substr(j, word_size);
                
                if(temp[word])
                {
                    total_words++;
                    temp[word] --;
                }
                else{
                    break;
                }
                
            }
            
            if(total_words == words.size())
            {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};