class Solution {
public:
    int rob(vector<int>& nums) {
        // It's just the House Robber I problem with extra steps, two subproblems, from [0...n - 2] and [1...n - 1]
        int n = nums.size();

        if(n == 1) return nums[0];

        int ans = INT_MIN;

        vector<int> dp(n + 2, 0);

        // From [0..n - 2]
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        ans = max(ans, dp[0]);

        fill(dp.begin(), dp.end(), 0);

        // From [1..n - 1]
        for(int i = n - 1; i >= 1; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        ans = max(ans, dp[1]);

        return ans;
    }
};
