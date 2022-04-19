class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> in(V);
	    for(int u = 0; u < V; u++) {
	        for(v : adj[u]) {
	            in[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int u = 0; u < V; u++) {
	        if(in[u] == 0) {
	            q.push(u);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int u = q.front();
	        q.pop();
	        topo.push_back(u);
	        for(int v : adj[u]) {
	            in[v]--;
	            if(in[v] == 0) {
	                q.push(v);
	            }
	        }
	    }
	    return topo;
	}
};