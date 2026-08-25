class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, INT_MAX);
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min({dp[i], ((i + 1 < n)? dp[i + 1] : 0), ((i + 2 < n)? dp[i + 2] : 0)});
        }

        return min(dp[0], dp[1]);
    }
};
