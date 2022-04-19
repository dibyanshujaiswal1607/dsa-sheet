class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int> key(V, INT_MAX), parent(V, -1), mstSet(V);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        key[0] = 0, parent[0] = -1;
        pq.push({0, 0});
        while(!pq.empty()) {
            int u = pq.top()[1];
            pq.pop();
            mstSet[u] = 1;
            for(vector<int> p : adj[u]) {
                int v = p[0], w = p[1];
                if(mstSet[v] == 0 and w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                    pq.push({key[v], v});
                }
            }
        }
        
        int cost = accumulate(key.begin(), key.end(), 0);
        return cost;
    }
};