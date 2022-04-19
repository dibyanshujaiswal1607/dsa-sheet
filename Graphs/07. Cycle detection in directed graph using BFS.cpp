class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> in(n);
        for(int u = 0; u < n; u++) {
            for(int v : adj[u]) {
                in[v]++;
            }
        }
        queue<int> q;
        for(int u = 0; u < n; u++) {
            if(in[u] == 0) {
                q.push(u);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(int v : adj[u]) {
                in[v]--;
                if(in[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(cnt == n)    return true;
        return false;
    }
};