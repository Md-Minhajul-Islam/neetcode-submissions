public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        
        int[] res = new int[nums.Length];

        for(int i = 0; i < nums.Length; i++)
        {
            int mul = 1;
            for(int j = 0; j < nums.Length; j++){
                if(i != j) mul *= nums[j];
            }
            res[i] = mul;
        }
        return res;
    }
}
