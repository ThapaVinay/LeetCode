/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    int index = 0;
    int find_peak(MountainArray arr, int start, int end)
    {
        int mid = (start+end)/2;
        if(start<end)
        {
            if(arr.get(mid) < arr.get(mid+1))
            {
                 find_peak(arr,mid+1,end);
            }
            else{
                 find_peak(arr,start,mid);
            }
        }
        if(start == end)
        {
            index =  start;
        }
        return index;
    }

    
    int binary(MountainArray arr, int start, int end, int target)
    {
        
        int mid = (start+end)/2;
        boolean flag1 = false;
        boolean flag = (arr.get(mid) < arr.get(mid+1));
        while(start < end)
        {
            mid = (start+end)/2;
            if(arr.get(mid) == target)
            {
                flag1 = true;
                break;
            }
            else if(flag)
            {
                if(arr.get(mid) < target)
                    start = mid+1;
                else
                    end = mid;
            }  
            else
            {
                if(arr.get(mid) < target)
                    end = mid;
                else
                    start = mid+1;
            }
        }
        if(flag1)
            return mid;
        else if(start == end && arr.get(start) == target)
            return start;
        else 
            return -1;
    }
    
    public int findInMountainArray(int target, MountainArray arr) {
        int start = 0, end = arr.length()-1;
        int index = find_peak(arr, start, end);
        int index1 = binary(arr,index,end,target);
        int index2 = binary(arr,start,index,target);
        if(index1 == -1)
        {
            return index2;
        }
        else if(index2 == -1)
        {
            return index1;
        }
        else if(index1 < index2)
        {
            return index1;
        }
        else{
            return index2;
        }
    }
}