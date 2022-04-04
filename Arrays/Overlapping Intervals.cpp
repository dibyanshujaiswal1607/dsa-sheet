#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         int n = intervals.size();
         vector<vector<int>> ans;
         sort(intervals.begin(), intervals.end());
         int i = 0;
         while(i < n) {
             int left = intervals[i][0], right = intervals[i][1];
             int j = i + 1;
             while(j < n and intervals[j][0] <= right) {
                 right = max(right, intervals[j][1]);
                 j++;
             }
             ans.push_back({left, right});
             i = j;
         }
         return ans;
    }
};