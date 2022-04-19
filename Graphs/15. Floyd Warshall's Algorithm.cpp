class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    // if there isn't an edge from i to j then matrix[i][j] = -1
	    int n = matrix.size();
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == -1) {
	                matrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    for(int k = 0; k < n; k++) { // for all intermediate nodes
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
	                if(matrix[i][k] == INT_MAX or matrix[k][j] == INT_MAX) {
	                    continue;
	                } else if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	            }
	        }
	    }
		// to check for negative cycle, if there is a negative distance then there is a negative cycle
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == INT_MAX) {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};