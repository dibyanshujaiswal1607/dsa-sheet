#include <bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // idea is to calculate water filling on each index
        // water can be filled in the index when it has a greater block on left and greater block on right
        // so we PRECALCULATE the max element on left and right for each element
        int left[n], right[n];
        left[0] = arr[0];
        right[n - 1] = arr[n - 1];
        for(int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);
        for(int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(left[i] > arr[i] and arr[i] < right[i]) {
                ans += min(left[i], right[i]) - arr[i];
            }
        }
        return ans;
    }
};