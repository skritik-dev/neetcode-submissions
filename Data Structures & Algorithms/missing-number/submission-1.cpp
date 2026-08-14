class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) nums[0] ^= nums[i];
        for(int i = 0; i <= n; i++) nums[0] ^= i;
        return nums[0];    
    }
};
