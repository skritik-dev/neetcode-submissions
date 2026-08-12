class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int req = target - nums[i];

            int index = lower_bound(nums.begin(), nums.end(), req) - nums.begin();

            if(index < n && index != i && nums[index] == req) {
                if(i > index) swap(i, index);
                return {i + 1, index + 1};
            }
        }

        return {-1, -1};
    }
};
