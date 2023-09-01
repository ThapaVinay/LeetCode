class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum = 0;
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
        }
        
        double average = sum/k;
        int j = 0;
        for(int i=k; i<nums.size(); i++)
        {
            sum -= nums[j];
            sum += nums[i];
            double temp = sum/k;
            
            if(average < temp)
                average = temp;
            
            j++;
            
        }
        
        return average;
        
    }
};