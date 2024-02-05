class Solution {
public:
    
    int minGroups(vector<vector<int>>& intervals) {
        // store the left and right interval in a map
        // and at each point find the maximum overlapping intervals
        
        //edge case
        if(intervals.size() == 1)
            return 1;
        
        // initialisation
        int left[10000000] = {0}, right[10000000] = {0};
        int mini = INT_MAX;
        int maxi = 0;
        
        for(int i=0; i<intervals.size(); i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            // cout << x << " " << y << endl;
            
            left[x] ++;
            right[y] ++;
            
            maxi = max(maxi, y);
            mini = min(mini, x);
        }
        
        // now find overlapping points
        int curr = 0;
        int res = 0;
        
        while(mini <= maxi)
        {
            //  add left interval
            if(left[mini])
                curr += left[mini];
            
            res = max(res, curr);
            
            // remove right interval
            if(right[mini])
                curr -= right[mini];
            
            mini ++;
        }
        
        return res;
    }
};