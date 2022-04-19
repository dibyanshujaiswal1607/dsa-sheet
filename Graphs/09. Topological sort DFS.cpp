class Solution
{
	public:
	void dfs(int u, vector<bool> &vis, stack<int> &st, vector<int> adj[]) {
	    vis[u] = 1;
	    for(int v : adj[u]) {
	        if(!vis[v]) {
	            dfs(v, vis, st, adj);
	        }
	    }
	    st.push(u);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    stack<int> st;
	    vector<bool> vis(V);
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, st, adj);
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};