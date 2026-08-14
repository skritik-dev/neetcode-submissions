class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            res += min(leftMax[i], rightMax[i]) - nums[i];
        }

        return res;
    }
};