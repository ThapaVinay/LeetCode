class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        vector <int> preMax(n);
        vector <int> postMin(n);
        
        preMax[0] = arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            preMax[i] = max(preMax[i-1], arr[i]);
        }
        
        postMin[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            postMin[i] = min(postMin[i+1], arr[i]);
        }
        
        int count = 1;
        for(int i=0; i<arr.size()-1; i++)
        {
            if(preMax[i] <= postMin[i+1])
                count ++;
        }
        
        return count;
    }
};