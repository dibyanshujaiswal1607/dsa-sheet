class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// arrived = 0, departed = 1
    	vector<pair<int, bool>> timing;
    	for(int i = 0; i < n; i++) {
    	    timing.push_back({arr[i], 0});
    	    timing.push_back({dep[i], 1});
    	}
    	sort(timing.begin(), timing.end());
    	
    	int ans = 0, cnt = 0;
    	for(int i = 0; i < timing.size(); i++) {
    	    cnt = timing[i].second ? cnt - 1 : cnt + 1;
    	    ans = max(ans, cnt);
    	}
    	return ans;
    }
};

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int ans = 1, cnt = 1;
    	int i = 1, j = 0;
    	while(i < n and j < n) {
    	    if(arr[i] <= dep[j]) {
    	        cnt++;
    	        i++;
    	    } else {
    	        cnt--;
    	        j++;
    	    }
    	    ans = max(ans, cnt);
    	}
    	return ans;
    }
};