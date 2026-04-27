public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> set = new();
        for(int i = 0; i < nums.Length; i++) set.Add(nums[i]);

        int mx = 0;
        for(int i = 0; i < nums.Length; i++){
            if(set.Contains(nums[i]-1)) continue;

            int num = nums[i];
            int cnt = 0;
            while(set.Contains(num))
            {
                num++; cnt++;
            }
            mx = Math.Max(mx, cnt);
        }
        return mx;
    }
}
