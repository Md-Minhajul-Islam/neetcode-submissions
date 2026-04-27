public class Solution {

    public static int BinExpo(int b, int p)
    {
        int mul = 1;
        while(p > 0)
        {
            if((p & 1) == 1) mul *= b;
            b *= b;
            p >>= 1;
        }
        return mul;
    }

    public int[] ProductExceptSelf(int[] nums) {
        
        int[] count = new int[100];
        int countOfNeg = 0;

        for(int i = 0; i < nums.Length; i++)
        {
            if(nums[i] < 0)
            {
                countOfNeg++;
                count[-1*nums[i]]++;
            }
            else count[nums[i]]++;
        }

        for(int i = 0; i < nums.Length; i++)
        {
            int mul = 1;
            for(int j = 0; j < 100; j++)
            {
                int curr = nums[i];
                if(curr < 0) curr *= -1;
                int cnt = count[j] - (j == curr ? 1 : 0);
                
                if(j == 0 && cnt > 0) mul = 0;
                else if(j != 0 && cnt > 0) mul *= BinExpo(j, cnt);
            }
            if((countOfNeg-(nums[i] < 0 ? 1 : 0))%2 == 1) mul *= -1;

            nums[i] = mul;
        }
        return nums;

    }
}
