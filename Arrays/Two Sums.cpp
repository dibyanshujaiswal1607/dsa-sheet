class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()) {
                ans = {map[target - nums[i]], i};
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};