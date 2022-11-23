class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        HashMap <Integer,Integer> h = new HashMap<>();
        // int[] arr = new int[2];
        
        for(int i=0; i< nums.length ;i++)
        {
            if(h.containsKey(nums[i]))
            {
                return new int[]{h.get(nums[i]),i};
                // arr[0] = h.get(nums[i]);
                // arr[1] = i;
                // break;
            }else{
                h.put(target-nums[i],i);
            }
        }
        return null;
    }
}
