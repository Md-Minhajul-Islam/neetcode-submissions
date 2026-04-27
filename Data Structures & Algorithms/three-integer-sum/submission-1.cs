public class Solution {
    public List<List<int>> ThreeSum(int[] nums) {

        List<List<int>> res = new();
        HashSet<string> tupleSeen = new();
        HashSet<int> numSeen = new();

        for(int i = 0; i < nums.Length; i++)
        {
            for(int j = i+1; j < nums.Length; j++)
            {
                int num = -nums[i]-nums[j];
                List<int> temp = new List<int> {nums[i], nums[j], num};
                temp.Sort();
                string key = string.Join(",", temp);
                
                if(numSeen.Contains(num) && !tupleSeen.Contains(key))
                {
                    res.Add(new List<int> {nums[i], nums[j], num});
                    tupleSeen.Add(key);
                }
            }
            numSeen.Add(nums[i]);
        }
        return res;
    }
}
