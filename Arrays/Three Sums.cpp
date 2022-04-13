class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                if(nums[l] + nums[r] == -nums[i]) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // processing duplicates
                    while(l < r and nums[l] == ans.back()[1])   l++;
                    while(l < r and nums[r] == ans.back()[2])   r--;
                } else if(nums[l] + nums[r] < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }
            // processing duplicates
            while(i + 1 < n and nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};