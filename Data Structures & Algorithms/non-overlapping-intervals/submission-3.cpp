class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();

        // Sort based on the smallest interval
        sort(nums.begin(), nums.end(), [&](const vector<int>& a, const vector<int>& b) {
            return (a[1] < b[1]) || (a[1] == b[1] && a[0] > b[0]);
        });

        int res = 0;

        int prev_e = nums[0][1];
        for(int i = 1; i < n; i++) {
            int curr_s = nums[i][0], curr_e = nums[i][1];

            if(prev_e <= curr_s) {
                prev_e = curr_e;
            } else {
                res++;
            }
        }

        return res;
    }
};
