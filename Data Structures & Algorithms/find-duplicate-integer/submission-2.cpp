class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int bit = 0; bit < 31; bit++) {
            int mask = (1 << bit);

            int org = 0;
            for(int num = 1; num < n; num++) {
                org += (num & mask)? 1 : 0;
            }

            int act = 0;
            for(int i = 0; i < n; i++) {
                act += (nums[i] & mask)? 1 : 0;
            }

            if(act > org) {
                res |= mask;
            }
        }

        return res;
    }
};