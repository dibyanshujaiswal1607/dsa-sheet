#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> a, int n) {
        // code here
        // idea is to buy at local minimum and sell at local maximum
        vector<vector<int>> res;
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i - 1]) {
                res.push_back({i - 1, i});
            }
        }
        return res;
    }
};