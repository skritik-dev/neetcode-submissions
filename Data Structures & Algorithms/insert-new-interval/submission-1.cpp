class Solution {
    template<typename T>
    using v = vector<T>;

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> res;

        int prev_s = newInterval[0], prev_e = newInterval[1];

        for(int i = 0; i <= n; i++) {
            if(i == n) {
                res.push_back({prev_s, prev_e});
                continue;
            }

            int curr_s = intervals[i][0], curr_e = intervals[i][1];

            // Check for the disjoint condition
            if(prev_e < curr_s) {
                res.push_back({prev_s, prev_e});
                prev_s = curr_s;
                prev_e = curr_e;
            } else if(curr_e < prev_s) {
                res.push_back({curr_s, curr_e});
            } else {
                prev_s = min(prev_s, curr_s);
                prev_e = max(prev_e, curr_e);
            }
        }

        return res;
    }
};
