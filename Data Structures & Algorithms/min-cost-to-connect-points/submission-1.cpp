class Solution {
public:

    int find(int u, vector<int>& parent)
    {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }

    void Union(int u, int v, vector<int>& parent)
    {
        int a = find(u, parent), b = find(v, parent);
        if(a != b) parent[b] = a;
    }

    long long kruskalsAlgo(vector<vector<int>>& edges, int n)
    {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        sort(edges.begin(), edges.end());
        int totalDis = 0;
        for(auto& e: edges)
        {
            int w = e[0], u = e[1], v = e[2];
            if(find(u, parent) == find(v, parent)) continue;
            totalDis += 1ll*w;
            Union(u, v, parent);
        }
        return totalDis;
    }
    

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis, i, j});
            }
        }
        
        return kruskalsAlgo(edges, n);
    }
};
