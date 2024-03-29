class Solution {
private:
    static bool cmp(string &s1,string &s2){
        return s1.size() < s2.size();
    }

    bool checkPossible(string &s1,string &s2){
        // Base case
        int n = size(s1), m = size(s2);
        if(m-n != 1) return false;

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++, j++;
            }
            else{
                j++;
            }
        }

        return i == n;
    }

    int solve(vector<string> &words,int idx,int prev,int n){
        // Base case
        if(idx == n) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int c1 = 0;
        if(prev == -1 || checkPossible(words[prev],words[idx])){
            c1 = 1 + solve(words,idx+1,idx,n);
        }

        int c2 = solve(words,idx+1,prev,n);

        return dp[idx][prev+1] = max(c1,c2); 
    }
public:
    int dp[1001][1002];
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words),end(words),cmp);
        memset(dp,-1,sizeof(dp));
        return solve(words,0,-1,n);
    }
};