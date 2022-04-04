#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int start = 0, end = n;
        int realMid = (n + m + 1) / 2;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            int leftASize = mid, leftBSize = realMid - mid;
            
            int leftA = leftASize > 0 ? nums1[leftASize - 1] : INT_MIN;
            int leftB = leftBSize > 0 ? nums2[leftBSize - 1] : INT_MIN;
            int rightA = leftASize < n ? nums1[leftASize] : INT_MAX;
            int rightB = leftBSize < m ? nums2[leftBSize] : INT_MAX;
            
            // if correct partition is done
            if(leftA <= rightB and leftB <= rightA) {
                if((n + m) % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                } else {
                    return max(leftA, leftB);
                }
            } else if(leftA > rightB) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return 0.0;
    }
};