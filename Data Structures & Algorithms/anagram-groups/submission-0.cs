public class Solution {
    public List<List<string>> GroupAnagrams(string[] strs) {

        Dictionary<string, List<string>> dict = new();
        for(int i = 0; i < strs.Length; i++)
        {
            char[] arr = strs[i].ToCharArray();
            Array.Sort(arr);
            string key = new string(arr);

            dict.TryAdd(key, new List<string>());
            dict[key].Add(strs[i]);
        }

        List<List<string>> ans = new();
        foreach(var (key, list) in dict)
        {
            ans.Add(list);
        }
        return ans;
    }
}
