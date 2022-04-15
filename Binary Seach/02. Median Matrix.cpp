int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();

    int low = 1, high = 1e9;

    while(low <= high) {
        int mid = (low + high) / 2;
        int cntLessThanEqualToMid = 0;
        for(int i = 0; i < n; i++)
            cntLessThanEqualToMid += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        if(cntLessThanEqualToMid <= (n * m) / 2)    low = mid + 1;
        else    high = mid - 1;
    }
    return low;
}