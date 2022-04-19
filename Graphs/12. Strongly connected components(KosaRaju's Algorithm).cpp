#include <stack>
void dfs(int u, vector<bool>& vis, stack<int>& st, vector<int> adj[]) {
	vis[u] = 1;
	for(int v : adj[u]) {
		if(!vis[v]) {
			dfs(v, vis, st, adj);
		}
	}
	st.push(u);
}
void revDfs(int u, vector<bool>& vis, vector<int> transpose[], vector<int>& scc) {
	scc.push_back(u);
	vis[u] = 1;
	for(int v : transpose[u]) {
		if(!vis[v]) {
			revDfs(v, vis, transpose, scc);
		}
	}
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
	// KosaRaju's Algorithm
	// Step 1: Sort all the nodes in order of their finishing time, i.e, topological sort
	// Step 2: Transpose the graph, i.e, reverse all edges
	// Step 3: DFS according to finishing time
	vector<int> adj[n];
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i][0], v = edges[i][1];
		adj[u].push_back(v);
	}
	
	vector<bool> vis(n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			dfs(i, vis, st, adj);
		}
	}
	
	vector<int> transpose[n];
	for(int u = 0; u < n; u++) {
		vis[u] = 0;
		for(int v : adj[u]) {
			transpose[v].push_back(u);
		}
	}
	
	vector<vector<int>> res;
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		if(!vis[u]) {
			vector<int> scc;
			revDfs(u, vis, transpose, scc);
			res.push_back(scc);
		}
	}
	return res;
}