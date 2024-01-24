class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int total_gas =0;
        int total_cost = 0;
        
        int curr_gas = 0;
        int index = 0;
        
        for(int i=0; i<gas.size(); i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
            
            int diff = gas[i] - cost[i];
            curr_gas += diff;
            
            if(curr_gas < 0)
            {
                index = i+1;
                curr_gas = 0;
            }
        }
        
        if(total_gas - total_cost < 0)
            return -1;
        
        return index;
        
    }
};