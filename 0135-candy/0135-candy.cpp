class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector <int> res(ratings.size(), 1);
        
        for(int i=1; i<ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                res[i] = res[i-1] + 1;
            }
        }
        
        for(auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
        
        for(int i=ratings.size()-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                res[i] = max(res[i], res[i+1] + 1);
            }
        }
        
        int total = 0;
        for(auto i : res)
        {
            cout << i << " ";
            total += i;
        }
        cout << endl;
        return total;
    }
};