public class Solution {

    public static bool IsValid(char ch)
    {
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) return true;
        else return false;
    }

    public bool IsPalindrome(string s) {
        
        s = s.ToLower();

        int left = 0, right = s.Length-1;
        while(left < right)
        {
            if(IsValid(s[left]) && IsValid(s[right]))
            {
                if(s[left] != s[right]) return false;
                left++; right--;
            }
            else
            {
                if(!IsValid(s[left])) left++;
                if(!IsValid(s[right])) right--;
            }
        }
        return true;
    }
}
