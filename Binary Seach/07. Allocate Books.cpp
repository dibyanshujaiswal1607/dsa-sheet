bool isPossible(int m, vector<int> &A, int B) {
    int students = 1, pages = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > m)    return false;
        if(pages + A[i] > m) {
            students++;
            pages = 0;
        }
        pages += A[i];
    }
    if(students > B)    return false;
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size())    return -1;
    int low = *min_element(A.begin(), A.end()), high = 0;
    for(int a : A)  high += a;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(isPossible(mid, A, B)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
