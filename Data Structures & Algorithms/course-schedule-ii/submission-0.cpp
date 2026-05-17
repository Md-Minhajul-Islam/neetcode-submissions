class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        vector<bool> visited(numCourses), path(numCourses);
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        } 
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i]) continue;

            if(dfs(adj, visited, path, ans, i)) continue;
            else return {};
            
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& adj, vector<bool>&visited, vector<bool>& path, vector<int>& ans, int u)
    {
        visited[u] = true;
        path[u] = true;
        for(auto &v: adj[u])
        {
            if(!visited[v])
            {
                if(!dfs(adj, visited, path, ans, v)) return false;
            }
            else if(path[v]) return false;
        }
        ans.push_back(u);
        path[u] = false;
        return true;
    }
};
