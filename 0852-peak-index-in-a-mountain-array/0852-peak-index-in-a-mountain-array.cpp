class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size()-1;
        int mid = (start + end)/2;
        while(mid >= 0)
        {
            cout << mid <<endl;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid-1])
            {
                start = mid;
            }
            else 
            {
                end = mid;
            }
            mid = (start+end)/2;
        }
        
        return -1;
    }
};