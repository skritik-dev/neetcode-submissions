/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](const Interval& a, const Interval& b) {
            return (a.start < b.start) || (a.start == b.start && a.end < b.end);
        });

        int prev_e = nums[0].end;

        for(int i = 1; i < n; i++) {
            int curr_s = nums[i].start, curr_e = nums[i].end;

            if(prev_e <= curr_s) {
                prev_e = curr_e;
            } else {
                return false;
            }
        }

        return true;
    }
};
