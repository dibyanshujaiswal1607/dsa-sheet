class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ps(n), ns(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int length = ns[i] - ps[i] - 1;
            ans = max(ans, heights[i] * length);
        }
        return ans;
    }
};