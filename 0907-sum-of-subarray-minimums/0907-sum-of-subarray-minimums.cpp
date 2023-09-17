class Solution {
public:
    
    const int MOD = 1000000007;

    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        vector <int> left(n, -1), right(n,n);
        
        // to check left
        stack <int> s;
        for (int i = 0; i < n; ++i) 
        {
            while (!s.empty() && arr[i] < arr[s.top()]) 
            {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
                s.pop();
            }

        // Calculate the "right" array
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                s.pop();
            }
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        
        
        long long ans = 0;

        // Calculate the sum of minimums for each element in the array
        for (int i = 0; i < n; ++i) {
            ans += (long long)(i - left[i]) * (right[i] - i) * arr[i];
            ans %= MOD;
        }

        return ans;
    }
};