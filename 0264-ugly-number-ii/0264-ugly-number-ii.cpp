class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        priority_queue<long , vector<long >, greater<long >> pq;
        unordered_set<long long> seen;
        vector<int> primes = {2, 3, 5};
        
        pq.push(1);
        seen.insert(1);

        long long ugly = 1;
        for (int i = 0; i < n; i++) {
            ugly = pq.top();
            pq.pop();

            for (int prime : primes) {
                long long next = ugly * prime;
                if (!seen.count(next)) {
                    pq.push(next);
                    seen.insert(next);
                }
            }
        }

        return ugly;
    }
};
