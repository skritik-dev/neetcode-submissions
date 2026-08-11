class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n + 1, 0);

        const auto isValidDigit = [&](const int& l, const int& r) { // My approach has 'r' exclusive
            int num = 0;
            for(int i = l; i < r; i++) num = num * 10 + (s[i] - '0');
            return (num > 0 && num <= 26);
        };

        // Base recursion condition
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            if(i + 1 <= n && isValidDigit(i, i + 1)) dp[i] += dp[i + 1];
            if(i + 2 <= n && isValidDigit(i, i + 2)) dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};
