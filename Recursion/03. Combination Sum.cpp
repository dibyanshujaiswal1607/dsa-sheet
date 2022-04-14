class Solution {
public:
    void helper(int ind, int target, vector<int> &candidates, vector<int> &t, vector<vector<int>> &ans) {
        if(ind == candidates.size()) {
            if(target == 0) {
                ans.push_back(t);
            }
            return;
        }
        // pick
        if(candidates[ind] <= target) {
            t.push_back(candidates[ind]);
            helper(ind, target - candidates[ind], candidates, t, ans);
            t.pop_back();
        }
        helper(ind + 1, target, candidates, t, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        helper(0, target, candidates, t, ans);
        return ans;
    }
};