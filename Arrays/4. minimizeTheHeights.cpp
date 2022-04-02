#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int ans = arr[n-1] - arr[0];
        int smallest = arr[0] + k, largest = arr[n-1] - k;
        int mx, mn;
        // comparing adjacent elements for answer
        for(int i=0;i<n-1;i++) {
            mn = min(smallest, arr[i+1]-k);
            mx = max(largest, arr[i]+k);
            if(mn < 0)  continue;
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};