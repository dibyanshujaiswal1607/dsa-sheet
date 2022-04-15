#include <bits/stdc++.h>
using namespace std;

bool isPossible(int m, int x[], int n, int c) {
    int prev = 0;
    c--;
    for(int i = 1; i < n; i++) {
        if(c == 0)  return true;
        if(x[i] - x[prev] >= m) {
            c--;
            prev = i;
        }
    }
    if(c == 0)  return true;
    return false;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        int x[n];
        for(int i = 0; i < n; i++)  cin >> x[i];
        sort(x, x + n);

        int low = 1, high = x[n - 1];
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(mid, x, n, c)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << high << endl;
    }
    return 0;
}
