class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        stack<int> st;
        vector<int> nge(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() and st.top() <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return nge;
    }
};