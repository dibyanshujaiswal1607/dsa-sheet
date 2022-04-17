vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> pse(A.size());
    stack<int> st;
    for(int i = 0; i < A.size(); i++) {
        while(!st.empty() and st.top() >= A[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    return pse;
}
