class Solution {
  public:
    void bfs(int source, vector<int> adj[], vector<int> &vis, vector<int> &bfsTraversal) {
        queue<int> q;
        vis[source] = 1;
        q.push(source);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            bfsTraversal.push_back(u);
            for(int v : adj[u]) {
                if(vis[v] == 0) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfsTraversal, vis(V);
        bfs(0, adj, vis, bfsTraversal);
        return bfsTraversal;
    }
};