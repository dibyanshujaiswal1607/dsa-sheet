#include <bits/stdc++.h>
using namespace std;

const long long inf = 9e18;
pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> minMax = {inf, -inf};
    for(int i=0;i<n;i++) {
        minMax.first = min(minMax.first, a[i]);
        minMax.second = max(minMax.second, a[i]);
    }
    return minMax;
}