// memoization
int knapsack(int n, int w, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp) {
	if(n == 0 or w == 0)	return 0;
	if(dp[n - 1][w - 1] != -1)	return dp[n - 1][w - 1];
	if(weights[n - 1] > w)
		return dp[n - 1][w - 1] = knapsack(n - 1, w, values, weights, dp);
	else
		return dp[n - 1][w - 1] = max(values[n - 1] + knapsack(n - 1, w - weights[n - 1], values, weights, dp), knapsack(n - 1, w, values, weights, dp));
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(w, -1));
	return knapsack(n, w, values, weights, dp);
}

// top-down dp
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	// Write your code here
	vector<vector<int>> dp(n + 1, vector<int>(w + 1));
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			if(i == 0 or j == 0) {
				dp[i][j] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++) {
			if(weights[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
			}
		}
	}
	return dp[n][w];
}