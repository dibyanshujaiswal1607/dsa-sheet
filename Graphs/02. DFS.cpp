class Solution {
  public:
    void dfs(int u, vector<int> adj[], vector<int> &vis, vector<int> &dfsTraversal) {
        dfsTraversal.push_back(u);
        vis[u] = 1;
        for(int v : adj[u]) {
            if(vis[v] == 0) {
                dfs(v, adj, vis, dfsTraversal);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfsTraversal, vis(V);
        dfs(0, adj, vis, dfsTraversal);
        return dfsTraversal;
    }
};