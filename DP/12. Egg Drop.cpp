class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f, vector<vector<int>> &dp) {
        // base cases:
        // f = 0 -> 0
        // f = 1 -> 1
        // e = 0 -> X
        // e = 1 -> f
        if(f == 0 or f == 1 or e == 1)    return f;
        if(dp[e][f] != -1)  return dp[e][f];
        int mn = INT_MAX;
        for(int k = 1; k <= f; k++) {
            int mx = max(solve(e - 1, k - 1, dp), solve(e, f - k, dp));
            mn = min(mn, mx);
        }
        return dp[e][f] = 1 + mn;
    }
    int eggDrop(int n, int k) {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        // return solve(n, k, dp);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(j == 0 or j == 1 or i == 1) {
                    dp[i][j] = j;
                }
            }
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                int mn = INT_MAX;
                for(int f = 1; f <= j; f++) {
                    int mx = max(dp[i - 1][f - 1], dp[i][j - f]);
                    mn = min(mn, mx);
                }
                dp[i][j] = 1 + mn;
            }
        }
        return dp[n][k];
    }
};