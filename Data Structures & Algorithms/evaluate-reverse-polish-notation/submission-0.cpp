class Solution {
public:
    long long toDecimal(string s)
    {
        long long num = 0;
        
        for(auto& c: s)
        {
            if(c >= '0' && c <= '9') num = num*10ll+(c-'0');
        }
        if(s[0] == '-') num *= -1ll;
        return num;
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<long long> st;

        for(auto& t: tokens)
        {
            if(t.size() == 1 && (t == "-" || t == "+" || t == "*" || t == "/"))
            {
                long long num2 = st.top();
                st.pop();
                long long num1 = st.top();
                st.pop();
                
                if(t == "-") st.push(num1-num2);
                else if(t == "+") st.push(num1+num2);
                else if(t == "*") st.push(num1*num2);
                else if(t == "/") st.push(num1/num2);
            }
            else st.push(toDecimal(t));
        }
        return (int)st.top();

    }
};
