class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(index < n && nums[index] == target) return index;
        return -1;
    }
};
