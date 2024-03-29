// memoization
class Solution{
public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp) {
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int mn = INT_MAX;
        for(int k = i; k < j; k++) {
            int l = solve(i, k, arr, dp), r = solve(k + 1, j, arr, dp);
            int m = arr[i - 1] * arr[k] * arr[j];
            mn = min(mn, l + r + m);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[]) {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(1, N - 1, arr, dp);
    }
};