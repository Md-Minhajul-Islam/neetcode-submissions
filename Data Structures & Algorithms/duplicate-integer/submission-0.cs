public class Solution {
    public bool hasDuplicate(int[] nums) {
        
        Dictionary<int, bool> dic = new();
        foreach(int num in nums)
        {
            if(dic.ContainsKey(num)){
                return true;
            }
            dic.Add(num, true);
        }
        return false;
    }

}