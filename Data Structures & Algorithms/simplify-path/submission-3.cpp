class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        vector<string> st;
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(s.size() > 0)
                {
                    if(s == "."){}
                    else if(s == "..")
                    {
                        if(!st.empty()) st.pop_back();
                    }
                    else st.push_back(s);
                    s = "";
                }
            }
            else s += path[i];
        }
        if(!s.empty())
        {
            if(s == ".") {}
            else if(s == "..") st.pop_back();
            else st.push_back(s);
        }
        s = "/";
        for(int i = 0; i < st.size(); i++)
        {
            s += st[i];
            if(i < st.size()-1) s += "/";
        }
        return s;
    }
};