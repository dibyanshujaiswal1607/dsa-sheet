class Solution
{
public:
    void helper(int i, int sum, vector<int> &arr, int N, vector<int> &ans) {
        if(i == N) {
            ans.push_back(sum);
            return;
        }
        // pick the element
        helper(i + 1, sum + arr[i], arr, N, ans);
        // don't pick the element
        helper(i + 1, sum, arr, N, ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        vector<int> ans;
        helper(0, 0, arr, N, ans);
        return ans;
    }
};