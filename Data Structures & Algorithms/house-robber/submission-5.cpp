class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> result(nums.size() + 1);
        result[0] = 0;
        result[1] = nums[0];
        if(nums.size() > 1)
            result[2] = max(nums[1], nums[0]);
        if(nums.size() > 2) {
            for(int i = 3; i < nums.size() + 1; ++i) {
                result[i] = max(nums[i - 1] + result[i - 2], result[i-1]);
            }
        }
        return result[nums.size()];
    }
};
