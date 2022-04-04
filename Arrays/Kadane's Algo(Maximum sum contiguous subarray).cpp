#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.

    const long long inf = 9e18;
    long long maxSubarraySum(int a[], int n){
        long long ans = -inf, curSum = 0;
        for(int i=0;i<n;i++) {
            curSum += a[i];
            ans = max(ans, curSum);
            // start a new subarray whenever curSum goes negative
            if(curSum < 0)
                curSum = 0;
        }
        return ans;
    }
};