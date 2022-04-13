class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i] - 1) == s.end()) {
                int cnt = 1, t = nums[i] + 1;
                while(s.find(t) != s.end()) {
                    cnt++;  t++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};