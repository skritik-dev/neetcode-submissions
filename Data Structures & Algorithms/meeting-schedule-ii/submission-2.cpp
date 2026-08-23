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
    int minMeetingRooms(vector<Interval>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {
            if(!pq.empty() && pq.top() <= nums[i].start) {
                pq.pop();
            }

            pq.push(nums[i].end);
        }

        return (int) pq.size();
    }
};
