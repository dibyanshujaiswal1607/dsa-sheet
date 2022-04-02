pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> minMax = {9e18, -9e18};
    for(int i=0;i<n;i++) {
        minMax.first = min(minMax.first, a[i]);
        minMax.second = max(minMax.second, a[i]);
    }
    return minMax;
}