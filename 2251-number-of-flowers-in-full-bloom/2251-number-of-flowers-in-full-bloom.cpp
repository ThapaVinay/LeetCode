class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector <int> st;
        vector <int> et;
        
        for(int i=0; i<flowers.size(); i++)
        {
            st.push_back(flowers[i][0]);
            et.push_back(flowers[i][1]);
        }
        
        sort(st.begin(), st.end());
        sort(et.begin(), et.end());
        
        vector <int> res;
        for(int i=0; i<people.size(); i++)
        {
            int bloom = upper_bound(st.begin(), st.end(), people[i]) - st.begin();
            int dead = lower_bound(et.begin(), et.end(), people[i]) - et.begin();
            
            int seen = bloom - dead;
            
            res.push_back(seen);
        }
        
        return res;
    }
};