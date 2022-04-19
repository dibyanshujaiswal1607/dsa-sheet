class Solution {
public:
    bool checkCycle(int u, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &adj) {
        vis[u] = dfsVis[u] = 1;
        for(int v : adj[u]) {
            if(!vis[v]) {
                if(checkCycle(v, vis, dfsVis, adj)) return true;
            } else if(dfsVis[v]) {
                return true;
            }
        }
        dfsVis[u] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n), dfsVis(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(checkCycle(i, vis, dfsVis, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};