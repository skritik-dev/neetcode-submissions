class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {
            dp[i] += ((i + 1 < n + 1)? dp[i + 1] : 0) + ((i + 2 < n + 1)? dp[i + 2] : 0);
        }

        return dp[0];
    }
};
