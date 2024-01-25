class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        // first and last element of the array will be there.
        // So we need to find the remaining k-2 points.
        // At each break there will be two end points whose sum we need to maximise and minimise
        
        vector <long long> arr;
        
        for(int i=0; i<weights.size()-1; i++)
        {
            long long sum = weights[i] + weights[i+1];
            arr.push_back(sum);
        }
        
        sort(arr.begin(), arr.end());
        
        int i = 0, j = arr.size()-1;
        
        long long max_score = 0, min_score = 0;
        k = k-1;
        
        while(k--)
        {
            max_score += arr[j--];
            min_score += arr[i++];
        }
        
        return max_score - min_score;
        
    }
};