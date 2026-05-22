class Solution {
public:

    int dijkastra(int n, vector<vector<vector<int>>>& adj, int src, int dst, int k)
    {
        vector<vector<int>> dis(n, vector<int>(k+5, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        dis[src][0] = 0;
        minHeap.push({0, 0, src});

        while(!minHeap.empty())
        {
            auto v = minHeap.top();
            minHeap.pop();
            int cost = v[0], cnt = v[1], curr = v[2];

            if(curr == dst) return cost;

            if(cnt > k) continue;

            for(auto &a: adj[curr])
            {
                int co = a[0], cr = a[1]; 

                if(dis[cr][cnt+1] > dis[curr][cnt]+co)
                {
                    dis[cr][cnt+1] = dis[curr][cnt]+co;
                    minHeap.push({dis[cr][cnt+1], cnt+1, cr});
                }
            } 
        }
        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);

        for(auto& flight: flights)
        {
            int u = flight[0], v = flight[1], c = flight[2];
            adj[u].push_back({c, v});
        }

        return dijkastra(n, adj, src, dst, k);
    }
};
