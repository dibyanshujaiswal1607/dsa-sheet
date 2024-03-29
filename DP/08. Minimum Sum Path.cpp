class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 and j == m - 1)
                    dp[i][j] = grid[i][j];
                else if(i == n - 1)
                    dp[i][j] = dp[i][j + 1] + grid[i][j];
                else if(j == m - 1)
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};