// memoization
class Solution {
public:
    const int inf = 1e9;
    int solve(int n, int w, vector<int> &coins, vector<vector<int>> &dp) {
        if(w == 0)  return 0;
        if(n == 0)  return inf;
        if(dp[n - 1][w - 1] != -1) return dp[n - 1][w - 1];
        if(coins[n - 1] > w) {
            return dp[n - 1][w - 1] = solve(n - 1, w, coins, dp);
        } else {
            return dp[n - 1][w - 1] = min(1 + solve(n, w - coins[n - 1], coins, dp), solve(n - 1, w, coins, dp));
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount, -1));
        int res = solve(n, amount, coins, dp);
        return res == inf ? -1 : res;
    }
};

// top-down dp
class Solution {
public:
    const int inf = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                if(i == 0)  dp[i][j] = inf;
                if(j == 0)  dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
            }
        }
        return dp[n][amount] == inf ? -1 : dp[n][amount];
    }
};