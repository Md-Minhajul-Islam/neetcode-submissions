public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        
        Dictionary<int, int> count = new();
        foreach(int num in nums)
        {
            count[num] = count.GetValueOrDefault(num) + 1;
        }
        var sortedCount = count.OrderByDescending(n => n.Value).ToList();

        int[] ans = new int[k];
        for(int i = 0; i < k; i++) ans[i] = sortedCount[i].Key;
        return ans;
    }
}
