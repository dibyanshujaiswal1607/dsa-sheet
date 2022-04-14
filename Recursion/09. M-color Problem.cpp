bool isValid(int node, int color, vector<int> &colors, bool graph[101][101], int n) {
    for(int neighbour = 0; neighbour < n; neighbour++) {
        if(graph[node][neighbour] and colors[neighbour] == color) {
            return false;
        }
    }
    return true;
}
bool solve(vector<int> &colors, bool graph[101][101], int m, int n) {
    for(int node = 0; node < n; node++) {
        if(colors[node] == 0) {
            for(int color = 1; color <= m; color++) {
                if(isValid(node, color, colors, graph, n)) {
                    colors[node] = color;
                    if(solve(colors, graph, m, n)) return true;
                    else colors[node] = 0;
                }
            }
            return false;
        }
    }
    return true;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> colors(n);
    return solve(colors, graph, m, n);
}