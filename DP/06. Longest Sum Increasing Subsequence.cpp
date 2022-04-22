class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    for(int i = 0; i < n; i++) {
	        int mx = 0;
	        for(int j = 0; j < i; j++) {
	            if(arr[j] < arr[i]) {
	                mx = max(mx, dp[j]);
	            }
	        }
	        dp[i] = mx + arr[i];
	    }
	    return *max_element(dp.begin(), dp.end());
	}  
};