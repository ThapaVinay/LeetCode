class Solution {
public:
    vector<int> getRow(int r) {
        
        vector <int> curr;
        vector <int> prev;
        
        curr.push_back(1);
        if(r == 0)
        {
            return curr;
        }
        
        curr.push_back(1);
        if(r == 1)
            return curr;
        
        while(--r)
        {
            prev.push_back(1);
            for(int i=0; i<curr.size()-1; i++)
            {
                prev.push_back(curr[i] + curr[i+1]);
            }
            prev.push_back(1);
            
            curr = prev;
            prev.clear();
        }
        
        return curr;
    }
};