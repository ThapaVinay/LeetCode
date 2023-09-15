class RecentCounter {
public:
    vector <int> res;
    RecentCounter() {
    }
    
    int ping(int t) { 
        res.push_back(t);
        int s = t - 3000;
        int count = 0;
        for(int i=0; i<res.size(); i++)
        {
            if(res[i] >= s && res[i] <= t)
                count ++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */