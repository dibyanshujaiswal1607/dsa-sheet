class UnionFind {
    public:
    int size2;
    vector<int> sz, id;
    int numComponents;
    UnionFind(int size1) {
        size2 = size1;
        numComponents = size1;
        for (int i = 0; i < size1; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }
    int find1(int p) {
        int root = p;
        while (root != id[root]) root = id[root];
        while (p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }
    bool connected(int p, int q) {
        return find1(p) == find1(q);
    }
    int componentSize(int p) {
        return sz[find1(p)];
    }
    int sizecom() {
        return size2;
    }
    int components() {
        return numComponents;
    }
    void unify(int p, int q) {
        int root1 = find1(p);
        int root2 = find1(q);
        if (root1 == root2) return;
        if (sz[root1] < sz[root2]) {
            sz[root2] += sz[root1];
            id[root1] = root2;
            sz[root1] = 0;
        } else {
            sz[root1] += sz[root2];
            id[root2] = root1;
            sz[root2] = 0;
        }
        numComponents--;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<int>> edges;
        for(int u = 0; u < V; u++) {
            for(vector<int> t : adj[u]) {
                int v = t[0], w = t[1];
                edges.push_back({w, u, v});
            }
        }
        sort(edges.begin(), edges.end());
        
        vector<pair<int, int>> mst;
        UnionFind* dsu = new UnionFind(V);
        int cost = 0;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][1], v = edges[i][2], w = edges[i][0];
            if(!dsu->connected(u, v)) {
                cost += w;
                mst.push_back({u, v});
                dsu->unify(u, v);
            }
        }
        return cost;
    }
};