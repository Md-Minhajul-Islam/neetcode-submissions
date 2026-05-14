class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {

        stack<long long> st;

        for(auto& t: tokens)
        {
            if(t == "-" || t == "+" || t == "*" || t == "/")
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
            else st.push(stoll(t));
        }
        return (int)st.top();

    }
};
