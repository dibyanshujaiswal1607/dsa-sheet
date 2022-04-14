class Solution {
public:
    void helper(int ind, int target, vector<int> &candidates, vector<int> &t, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(t);
            return;
        }
        for(int i = ind; i < candidates.size(); i++) {
            if(i != ind and candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target)  break;
            t.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, t, ans);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        helper(0, target, candidates, t, ans);
        return ans;
    }
};