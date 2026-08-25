class Solution {
    // Treat each index as the center of the palindrome, for the odd length palindrome I've one center, but for the even length palindrome I've two center

public:
    string longestPalindrome(string s) {
        int n = s.length();

        int resLen = INT_MIN, resIdx = -1;

        for(int i = 0; i < n; i++) {
            // Odd length
            int l = i, r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resIdx = l;
                }

                --l;
                ++r;

            }

            // Even length
            l = i, r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resIdx = l;
                }

                --l;
                ++r;

            }
        } 

        return s.substr(resIdx, resLen);
    }
};
