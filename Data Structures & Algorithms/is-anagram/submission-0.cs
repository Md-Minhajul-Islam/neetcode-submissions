public class Solution {
    public bool IsAnagram(string s, string t) {

        int[] arr1 = new int[26];
        int[] arr2 = new int[26];

        foreach(char ch in s) arr1[ch-'a']++;
        foreach(char ch in t) arr2[ch-'a']++;

        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
}
