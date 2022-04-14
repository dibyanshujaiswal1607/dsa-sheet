class Solution {
public:
    void helper(int ind, vector<int> &nums, int n, vector<int> &t, vector<vector<int>> &ans) {
        ans.push_back(t);
        for(int i = ind; i < n; i++) {
            if(i != ind and nums[i] == nums[i - 1]) continue;
            t.push_back(nums[i]);
            helper(i + 1, nums, n, t, ans);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        sort(nums.begin(), nums.end());
        helper(0, nums, nums.size(), t, ans);
        return ans;
    }
};