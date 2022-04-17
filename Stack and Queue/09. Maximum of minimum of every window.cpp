vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
	vector<int> ps(n), ns(n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() and a[st.top()] >= a[i])	st.pop();
		ps[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	while(!st.empty())	st.pop();
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() and a[st.top()] >= a[i])	st.pop();
		ns[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	vector<int> ans(n, INT_MIN);
	for(int i = 0; i < n; i++) {
		int windowSize = ns[i] - ps[i] - 2;
		ans[windowSize] = max(ans[windowSize], a[i]);
	}
	for(int i = n - 2; i >= 0; i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	return ans;
}