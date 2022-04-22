// memoization
class Solution {
public:
    int LCS(string &x, string &y, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 or m == 0) {
            return 0;
        }
        if(dp[n - 1][m - 1] != -1) {
            return dp[n - 1][m - 1];
        }
        if(x[n - 1] == y[m - 1]) {
            return dp[n - 1][m - 1] = 1 + LCS(x, y, n - 1, m - 1, dp);
        } else {
            return dp[n - 1][m - 1] = max(LCS(x, y, n - 1, m, dp), LCS(x, y, n, m - 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return LCS(text1, text2, n, m, dp);
    }
};

// top-down dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 or j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};