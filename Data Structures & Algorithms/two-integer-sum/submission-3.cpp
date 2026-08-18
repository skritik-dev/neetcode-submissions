class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> seen;

        for(int i = 0; i < n; i++) {
            int req = target - nums[i];
            if(seen.find(req) != seen.end()) {
                return {seen[req], i};
            }

            seen[nums[i]] = i;
        }

        return {-1, -1};
    }
};
