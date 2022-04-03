#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        // window size is of number of good elements in array
        int good = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k)
                good++;
        }
        // initializing window
        int goodInWindow = 0;
        for(int i = 0; i < good; i++) {
            if(arr[i] <= k)
                goodInWindow++;
        }
        int res = good - goodInWindow;
        for(int i = good; i < n; i++) {
            if(arr[i] <= k)
                goodInWindow++;
            if(arr[i - good] <= k)
                goodInWindow--;
            res = min(res, good - goodInWindow);
        }
        return res;
    }
};