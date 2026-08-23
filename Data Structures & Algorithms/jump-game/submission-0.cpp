class Solution {
    // int n;

    // bool solve(int i, vector<int>& nums) {
    //     if(i == n - 1) return true;

    //     bool ans = false;
    //     for(int j = 1; j <= nums[i]; j++) {
    //         if(i + j >= n) break;
    //         ans |= solve(i + j, nums);
    //     }

    //     return ans;
    // }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= n) break;
                dp[i] = dp[i] || dp[i + j];
            }
        }

        return dp[0];
    }
};
