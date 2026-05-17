class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        } 

        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;
            cnt++;
            dfs(adj, visited, i);
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>&visited, int u)
    {
        visited[u] = true;
        for(auto &v: adj[u])
        {
            if(!visited[v]) dfs(adj, visited, v);
        }
    }
};
