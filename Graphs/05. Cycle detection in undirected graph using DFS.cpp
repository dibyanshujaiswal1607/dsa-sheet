bool checkCycle(int u, int p, vector<bool> &vis, vector<vector<int>> &adj) {
	vis[u] = 1;
	for(int v : adj[u]) {
		if(!vis[v]) {
			if(checkCycle(v, u, vis, adj))	return true;
		} else if(v != p) {
			return true;
		}
	}
	return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    // Write your code here.
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u = edges[i][0], v = edges[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n + 1);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			if(checkCycle(i, -1, vis, adj)) {
				return "Yes";
			}
		}
	}
	return "No";
}
