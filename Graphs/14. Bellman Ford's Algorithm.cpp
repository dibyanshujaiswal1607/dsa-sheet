class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        int inf = 1e8;
        vector<int> distance(V, inf);
        distance[S] = 0;
        
        // relax all the edges n - 1 times
        for(int i = 0; i < V - 1; i++) {
            for(vector<int> t : adj) {
                int u = t[0], v = t[1], w = t[2];
                if(distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
        
        // to detect a negative cycle
        // relax one more time, if any of the distance reduce, that means there is a negative cycle
        return distance;
    }
};