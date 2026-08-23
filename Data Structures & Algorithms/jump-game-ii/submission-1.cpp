class Solution {
    int n;

    vector<int> dp;

    int solve(int i, vector<int>& nums) {
        if(i == n - 1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j = 1; j <= nums[i]; j++) {
            if(i + j >= n) break;
            int temp = solve(i + j, nums);
            if(temp != INT_MAX) ans = min(ans, temp + 1);
        }

        return dp[i] = ans;
    }

public:
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
};
