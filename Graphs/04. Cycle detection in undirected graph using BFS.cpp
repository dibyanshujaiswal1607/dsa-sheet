#include <queue>
bool checkCycle(int source, vector<bool> &vis, vector<vector<int>> &adj) {
	queue<pair<int, int>> q;
	vis[source] = 1;
	q.push({source, -1});
	while(!q.empty()) {
		int u = q.front().first, p = q.front().second;
		q.pop();
		for(int v : adj[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				q.push({v, u});
			} else if(v != p) {
				return true;
			}
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
			if(checkCycle(i, vis, adj)) {
				return "Yes";
			}
		}
	}
	return "No";
}
