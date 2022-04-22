class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> s;
        for(string b : B)   s.insert(b);
        
        int n = A.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(s.find(A.substr(j, i - j + 1)) != s.end()) {
                    if(j > 0)
                        dp[i] += dp[j - 1];
                    else
                        dp[i] += 1;
                }
            }
        }
        
        if(dp[n - 1] > 0)   return 1;
        else    return 0;
    }
};