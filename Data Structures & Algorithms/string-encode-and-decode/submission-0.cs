public class Solution {

    public string Encode(IList<string> strs) {
        StringBuilder encoded = new();
        foreach(var str in strs)
        {
            encoded.Append('ñ');
            encoded.Append(str);
        }
        return encoded.ToString();
    }

    public List<string> Decode(string s) {
        List<string> decoded = new();
        for(int i = 0; i < s.Length; )
        {
            StringBuilder str = new();
            if(s[i] == 'ñ'){
                ++i;
                while(i < s.Length && s[i] != 'ñ')
                {
                    str.Append(s[i]);
                    i++;
                }
                decoded.Add(str.ToString());
            }
        }
        return decoded;
   }
}
