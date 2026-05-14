class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for(auto c: s)
        {
            if(closeToOpen.count(c))
            {
                if(st.empty() || st.top() != closeToOpen[c]) return false;
                st.pop();
            }
            else st.push(c);
        }
        return st.empty();
    }
};
