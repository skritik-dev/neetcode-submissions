class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int num = 0; num <= n; num++) {
            res[num] = __builtin_popcount(num);
        }

        return res;
    }
};
