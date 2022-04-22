class Solution{
public:
    bool isPalin(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    int solve(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(isPalin(s, i, j)) return dp[i][j] = 0;
        int mn = INT_MAX;
        for(int k = i; k < j; k++) {
            int temp = solve(i, k, s, dp) + solve(k + 1, j, s, dp);
            mn = min(mn, temp);
        }
        return dp[i][j] = 1 + mn;
    }
    int palindromicPartition(string str) {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, str, dp);
    }
};