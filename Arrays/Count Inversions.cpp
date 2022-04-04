#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans;
    void merge(long long arr[], long long temp[], long long l, long long mid, long long r) {
        long long i = l, j = mid + 1, k = l;
        while (i <= mid and j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                ans += mid - i + 1;
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (k = l; k <= r; k++) {
            arr[k] = temp[k];
        }
    }
    void mergeSort(long long arr[], long long temp[], long long l, long long r) {
        if(l < r) {
            long long mid = (l + r) / 2;
            mergeSort(arr, temp, l, mid);
            mergeSort(arr, temp, mid + 1, r);
            merge(arr, temp, l, mid, r);
        }
    }
    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here
        long long temp[N];
        ans = 0;
        mergeSort(arr, temp, 0, N - 1);
        return ans;
    }
};