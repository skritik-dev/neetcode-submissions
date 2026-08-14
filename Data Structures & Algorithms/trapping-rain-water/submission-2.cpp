class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;

        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[i] >= nums[stk.top()]) {
                int curr = nums[stk.top()];
                stk.pop();

                if(!stk.empty()) {
                    int l = stk.top(), r = i;
                    res += (r - l - 1) * (min(nums[l], nums[r]) - curr);
                }
            }

            stk.push(i);
        }

        return res;
    }
};