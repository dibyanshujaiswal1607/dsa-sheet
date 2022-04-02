#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    int partition(int arr[], int l, int r) {
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
 
    // Picks a random pivot element between l and r and partitions
    // arr[l..r] around the randomly picked element using partition()
    int randomPartition(int arr[], int l, int r) {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        return partition(arr, l, r);
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        // If k is smaller than number of elements in array
        if (k > 0 && k <= r - l + 1) {
            // Partition the array around a random element and
            // get position of pivot element in sorted array
            int pos = randomPartition(arr, l, r);
            
            // If position is same as k
            if (pos-l == k-1)
                return arr[pos];
            if (pos-l > k-1) // If position is more, recur for left subarray
                return kthSmallest(arr, l, pos-1, k);
            // Else recur for right subarray
            return kthSmallest(arr, pos+1, r, k-pos+l-1);
        }
        // If k is more than the number of elements in the array
        return INT_MAX;
    }
};