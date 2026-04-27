public class Solution {
    public bool IsAnagram(string s, string t) {

        int[] count = new int[26];

        foreach(char ch in s) count[ch-'a']++;
        
        foreach(char ch in t) count[ch-'a']--;

        for(int i = 0; i < 26; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
}
