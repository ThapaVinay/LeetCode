class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        // sort and keep making pairs of difference < k
        
        sort(nums.begin(), nums.end());
        
        
        vector<vector<int>> res;
        vector<int> temp;

        for(int i=0; i<nums.size(); i++)
        {
            if((temp.size() && nums[i] - temp.front() > k) || temp.size() == 3)
            {
                if(temp.size() != 3)
                    return {};
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        
        if(temp.size() && temp.size() < 3)
        {
            return {};
        }
        
        if(temp.size())
            res.push_back(temp);
        
        return res;
        
        
    }
};