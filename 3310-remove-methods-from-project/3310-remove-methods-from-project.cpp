class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for(int next : adj[node])
        {
            if(!vis[next])
                dfs(next, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        // Build graph
        for(auto &it : invocations)
        {
            adj[it[0]].push_back(it[1]);
        }

        // Find suspicious methods
        vector<int> vis(n,0);

        dfs(k, adj, vis);

        // Check outside -> inside
        for(auto &it : invocations)
        {
            int u = it[0];
            int v = it[1];

            if(vis[u]==0 && vis[v]==1)
            {
                vector<int> ans;

                for(int i=0;i<n;i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // Keep only non-suspicious methods
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                ans.push_back(i);
        }

        return ans;
    }
};