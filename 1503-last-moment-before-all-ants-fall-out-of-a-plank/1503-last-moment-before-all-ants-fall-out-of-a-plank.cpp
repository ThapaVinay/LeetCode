class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        // just assume that the ants are magical and pass each other
        
        int result = 0;
        
        // ants going towards left
        for(auto l: left)
        {
            result = max(l, result);
        }
        
        // ants going towards right
        for(auto r: right)
        {
            result = max(result, n-r);
        }
        
        return result;
        
    }
};