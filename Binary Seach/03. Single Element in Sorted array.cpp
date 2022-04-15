class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1 1 2 3 3 4 4 8 8
        // 0 1 2 3 4 5 6 7 8
        // observation: in left half even odd pair contains same element like 0,1 - 2,3
        // and in right half its different
        int low = 0, high = nums.size() - 2;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};