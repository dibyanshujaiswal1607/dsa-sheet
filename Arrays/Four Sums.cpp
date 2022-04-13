class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int left = j + 1, right = n - 1;
                int n12 = nums[i] + nums[j], n34 = target - n12;
                while(left < right) {
                    if(nums[left] + nums[right] == n34) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // processing duplicates of number 3
                        while(left < right and nums[left] == ans.back()[2])    left++;
                        //processing duplicates of number 4
                        while(left < right and nums[right] == ans.back()[3]) right--;
                    } else if(nums[left] + nums[right] < n34) {
                        left++;
                    } else {
                        right--;
                    }
                }
                // procesing duplicates of number 2
                while(j + 1 < n and nums[j + 1] == nums[j]) j++;
            }
            // processing duplicates of number 1
            while(i + 1 < n and nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};