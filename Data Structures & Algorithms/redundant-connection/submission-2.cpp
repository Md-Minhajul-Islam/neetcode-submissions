class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+5);
        vector<int> degree(n+5);

        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        } 
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            if(degree[i] == 1) 
            {
                cout << i << "\n";
                q.push(i);
            }
        }
        vector<bool> vis(n+5);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            degree[u]--;
            vis[u] = true;
            for(auto& v: adj[u])
            {
                if(vis[v]) continue;
                degree[v]--;
                if(degree[v] == 1) q.push(v);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cout << degree[i] << "\n";
        }
        for(int i = n-1; i >= 0; i--)
        {
            int u = edges[i][0], v = edges[i][1]; 
            if(degree[u] && degree[v]) return {u, v};
        }
        return {};
    }

};
