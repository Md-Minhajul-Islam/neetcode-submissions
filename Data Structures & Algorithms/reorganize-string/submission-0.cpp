class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(30);
        for(auto &c: s) cnt[c-'a']++;

        priority_queue<pair<int, char>> maxHeap;
        for(int i = 0; i < 30; i++)
        {
            if(cnt[i]) maxHeap.push({cnt[i], (char)('a'+i)});
        }
        string str = "#";
        while(!maxHeap.empty())
        {
            auto [cnt, ch] = maxHeap.top();
            maxHeap.pop();
            if(ch != str.back())
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
                str += ch2;
                cnt2--;
                if(cnt2) maxHeap.push({cnt2, ch});
            }
            else return "";
        }
        return str.substr(1);

    }
};