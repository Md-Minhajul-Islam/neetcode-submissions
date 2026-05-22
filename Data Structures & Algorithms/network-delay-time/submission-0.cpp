class Solution {
public:
    int dijkastra(vector<vector<vector<int>>>& adj, int n, int k)
    {
        vector<int> t(n+5, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        minHeap.push({0, k});
        t[k] = 0;
        while(!minHeap.empty())
        {
            auto v = minHeap.top();
            minHeap.pop();

            int u = v[1];

            for(auto& a: adj[u])
            {
                int v = a[1], time = a[0];
                if(t[v] > t[u]+time)
                {
                    t[v] = t[u]+time;
                    minHeap.push({t[v], v});
                }
            }
        }

        int mx = t[k];
        for(int i = 1; i <= n; i++) mx = max(t[i], mx);
        
        return mx == INT_MAX ? -1 : mx;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>> adj(n+5);
        for(auto t: times)
        {
            int u = t[0], v = t[1], time = t[2];
            adj[u].push_back({time, v});
        }
        
        return dijkastra(adj, n, k);
    }
};
