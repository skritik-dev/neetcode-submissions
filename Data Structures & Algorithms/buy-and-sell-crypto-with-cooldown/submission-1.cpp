class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));

        for(int i = n - 1; i >= 0; --i) {
            dp[i][0] = max({dp[i + 1][0], -nums[i] + dp[i + 1][1]});
            dp[i][1] = max({dp[i + 1][1], nums[i] + dp[i + 2][0]});
        }

        return dp[0][0];
    }
};