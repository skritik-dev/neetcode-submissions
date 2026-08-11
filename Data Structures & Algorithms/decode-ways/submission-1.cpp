class Solution {
    int n;
    string s;

    vector<int> t;

    bool isValidDigit(int l, int r) { // My approach has 'r' exclusive
        int num = 0;
        for(int i = l; i < r; i++) num = num * 10 + (s[i] - '0');
        return (num > 0 && num <= 26);
    }


    int solve(int i) {
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(t[i] != -1) return t[i];
        int res = 0;
        // Take one digit
        if(i + 1 <= n && isValidDigit(i, i + 1)) res += solve(i + 1);

        // Take two digit
        if(i + 2 <= n && isValidDigit(i, i + 2)) res += solve(i + 2);

        return t[i] = res;
    }

public:
    int numDecodings(string s) {
        n = s.size();
        this->s = s;
        t.assign(n + 1, -1);
        return solve(0);
    }
};
