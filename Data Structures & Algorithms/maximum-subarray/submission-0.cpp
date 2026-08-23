class Solution {
    // You can't mess around with Kadane's algorithm

public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MIN, curr = 0;
        for(int i = 0; i < n; i++) {
            curr += nums[i];
            res = max(curr, res);
            if(curr < 0) curr = 0;
        }

        return res;
    }
};
