class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> num1;
        unordered_set <int> num2;
        vector<vector<int>> res;
        
        for(int i=0; i<nums1.size(); i++)
        {
            num1.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++)
        {
            num2.insert(nums2[i]);
        }
        
        
        
        vector <int> temp;
        for(auto i: num1)
        { 
            if(num2.find(i) == num2.end())
            {
                temp.push_back(i);
            }
        }
        res.push_back(temp);
        
        temp.clear();
        for(auto i : num2)
        { 
            if(num1.find(i) == num1.end())
            {
                temp.push_back(i);
            }
        }
        res.push_back(temp);
        
        return res;
    }
};