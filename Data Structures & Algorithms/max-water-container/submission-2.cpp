class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        
        int res = INT_MIN;
        while(l < r) {
            res = max(res, min(nums[l], nums[r]) * (r - l));
            if(nums[l] < nums[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
