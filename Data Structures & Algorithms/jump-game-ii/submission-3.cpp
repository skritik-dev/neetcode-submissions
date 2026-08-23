class Solution {
    // int n;

    // vector<int> dp;

    // int solve(int i, vector<int>& nums) {
    //     if(i == n - 1) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int ans = INT_MAX;
    //     for(int j = 1; j <= nums[i]; j++) {
    //         if(i + j >= n) break;
    //         int temp = solve(i + j, nums);
    //         if(temp != INT_MAX) ans = min(ans, temp + 1);
    //     }

    //     return dp[i] = ans;
    // }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= n) break;
                if(dp[i + j] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }

        return dp[0];
    }
};
