#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    pair<int, int> subArrayWithGivenSum(int arr[], int n, int sum) {
        unordered_map<int, int> map;
        int start = 0, end = -1;
        int curSum = 0;
        for(int i = 0; i < n; i++) {
            curSum += arr[i];
            if(curSum == sum) {
                end = i;
                break;
            }
            if(map.find(curSum - sum) != map.end()) {
                start = map[curSum - sum] + 1, end = i;
                break;
            }
            map[curSum] = i;
        }
        return {start, end};
    }
};