public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        
        Dictionary<int, int> count = new();
        foreach(int num in nums)
        {
            count[num] = count.GetValueOrDefault(num) + 1;
        }
        List<int>[] bucket = new List<int>[nums.Length+1];

        foreach(var pair in count)
        {
            if(bucket[pair.Value] == null) bucket[pair.Value] = new List<int>();
            bucket[pair.Value].Add(pair.Key);
        }

        List<int> result = new();

        for(int i = bucket.Length-1; i >= 0; i--)
        {
            if(bucket[i] != null) result.AddRange(bucket[i]);
        }

        return result.Take(k).ToArray();
    }
}
