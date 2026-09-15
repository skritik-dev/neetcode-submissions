class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};
