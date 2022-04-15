double multiply(double mid, double n) {
	double res = 1.0;
	for(int i = 0; i < n; i++) {
		res *= mid;
	}
	return res;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
	double low = 1, high = m + 1;
	double eps = 1e-7;
	while(high - low > eps) {
		double mid = (low + high) / 2.0;
		if(multiply(mid, n) <= m) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return low;
}