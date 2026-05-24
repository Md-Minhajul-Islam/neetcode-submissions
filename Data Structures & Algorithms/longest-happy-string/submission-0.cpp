class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if(a) maxHeap.push({a, 'a'});
        if(b) maxHeap.push({b, 'b'});
        if(c) maxHeap.push({c, 'c'});


        string str = "##";
        while(!maxHeap.empty())
        {
            auto [cnt, ch] = maxHeap.top();
            maxHeap.pop();
            string temp = str.substr(str.size()-2);
            if(temp+ch != "aaa" && temp+ch != "bbb" && temp+ch != "ccc")
            {
                str += ch;
                cnt--;
                if(cnt) maxHeap.push({cnt, ch});
            }
            else if(!maxHeap.empty())
            {
                auto [cnt2, ch2] = maxHeap.top();
                maxHeap.pop();
                maxHeap.push({cnt, ch});
                if(temp+ch2 != "aaa" && temp+ch2 != "bbb" && temp+ch2 != "ccc")
                {
                    str += ch2;
                    cnt2--;
                    if(cnt2) maxHeap.push({cnt2, ch2});
                }
            }
            else break;
        }
        return str.substr(2);
    }
};