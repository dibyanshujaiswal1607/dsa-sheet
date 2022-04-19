class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> distance(V, INT_MAX);
        
        distance[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()) {
            int u = pq.top()[1];
            pq.pop();
            for(vector<int> p : adj[u]) {
                int v = p[0], d = p[1];
                if(distance[u] + d < distance[v]) {
                    distance[v] = distance[u] + d;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance;
    }
};