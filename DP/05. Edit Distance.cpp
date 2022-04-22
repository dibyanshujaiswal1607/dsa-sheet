// memoization
class Solution {
public:
    int dynamic(string &a, string &b, int n, int m, vector<vector<int>> &dp) {
        if(n == 0)  return m;
        if(m == 0)  return n;
        if(dp[n - 1][m - 1] != -1)  return dp[n - 1][m - 1];
        if(a[n - 1] == b[m - 1]) {
            return dp[n - 1][m - 1] = dynamic(a, b, n - 1, m - 1, dp);
        } else {
            int ins = dynamic(a, b, n, m - 1, dp);
            int del = dynamic(a, b, n - 1, m, dp);
            int rep = dynamic(a, b, n - 1, m - 1, dp);
            return dp[n - 1][m - 1] = 1 + min({ins, del, rep});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dynamic(word1, word2, n, m, dp);
    }
};

// top-down dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0)  dp[i][j] = j;
                if(j == 0)  dp[i][j] = i;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
};