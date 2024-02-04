class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        // put the start time and the end time of the trips in a map and
        // at each time find the curr capacity of the car
        
        unordered_map <int, int> start, end;
        int first = INT_MAX, last = 0;
        
        for(auto arr : trips)
        {
            start[arr[1]] += arr[0];
            end[arr[2]] += arr[0];
            
            // finding the first and last pick up stop
            first = min(first, arr[1]);
            last = max(last, arr[2]);
        }
        
        // now check capacity from the stop of first passenger to the last one
        while(first <= last)
        {
            // we drop the passenger
            if(end[first] > 0)
            {
                capacity += end[first];
            }
            
            // we pick up passenger
            if(start[first] > 0)
            {
                capacity -= start[first];
                
                if(capacity < 0)
                    return false;
            }
            first ++;
        }
        
        return true; 
    }
};