class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> cnt(30);
        for(auto&c: tasks) cnt[c-'A']++;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < 30; i++)
        {
            if(cnt[i]) pq.push({cnt[i], i});
        }
        int t = 0;
        vector<int> time(30, -1000);
        while(!pq.empty())
        {
            vector<pair<int, int>> temp;
            while(!pq.empty() && t-time[pq.top().second] <= n)
            {
                temp.push_back(pq.top());
                pq.pop();
            }
            if(pq.empty()) t++;
            else
            {
                auto [c, ind] = pq.top();
                pq.pop();
                time[ind] = t;
                c--;
                if(c) pq.push({c, ind});
                t++;
            }
            while(!temp.empty())
            {
                pq.push({temp.back()});
                temp.pop_back();
            }
        }
        return t;
    }
};
