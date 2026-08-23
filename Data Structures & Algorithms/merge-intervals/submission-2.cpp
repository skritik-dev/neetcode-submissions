class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.reserve(n);

        int prev_s = intervals[0][0], prev_e = intervals[0][1];

        for(int i = 1; i <= n; i++) {
            if(i == n) {
                res.push_back({prev_s, prev_e});
                continue;
            }

            int curr_s = intervals[i][0], curr_e = intervals[i][1];

            if(prev_e < curr_s) {
                res.push_back({prev_s, prev_e});
                prev_s = curr_s;
                prev_e = curr_e;
            } else {
                prev_e = max(prev_e, curr_e);
            }
        }

        return res;
    }
};
