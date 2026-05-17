class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n), path(n);

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        } 

        if(!dfs(adj, visited, -1, 0)) return false;

        for(int i = 0; i < n; i++) if(!visited[i]) return false;
        return true;
    }

    bool dfs(vector<vector<int>>& adj, vector<bool>&visited, int parent, int u)
    {
        visited[u] = true;
        for(auto &v: adj[u])
        {
            if(!visited[v])
            {
                if(!dfs(adj, visited, u, v)) return false;
            }
            else if(v != parent) return false;
        }
        return true;
    }
};
