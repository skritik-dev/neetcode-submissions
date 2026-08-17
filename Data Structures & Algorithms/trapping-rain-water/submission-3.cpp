class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        // Monotonic decreasing stack
        stack<int> s;

        int res = 0;
        for(int r = 0; r < n; r++) {
            while(!s.empty() && nums[s.top()] <= nums[r]) {
                // Left partition (l) + mid base (m) + right partition (r)
                int m = nums[s.top()];
                s.pop();

                if(!s.empty()) {
                    int l = s.top();
                    res += (r - l - 1) * (min(nums[l], nums[r]) - m);
                }
            }

            s.push(r);
        }

        return res;
    }
};
