class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        double [] temp = new double[m+n];
        for(int i=0,j=0,k=0 ;i< m+n ;i++)
        {
            if(j == nums1.length)
            {
                temp[i] = nums2[k];
                k++;
                continue;
            }
            if(k == nums2.length)
            {
                temp[i] = nums1[j];
                j++;
                continue;
            }
            if(nums1[j] < nums2[k])
            {
                temp[i] = nums1[j];
                j++;
            }
            else{
                temp[i] = nums2[k];
                k++;
            }
        }
        int mid = (m+n)/2;
        
        if((m+n) % 2 == 0)
        {
            return (temp[mid] + temp[mid-1])/2;
        }else{
            return temp[mid];
        }
    }
}