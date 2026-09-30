class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> rob1(nums.size());
        vector<int> rob2(nums.size());
        rob1[0] = nums[0];
        rob1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size() - 1; ++i) {
            rob1[i] = max(rob1[i - 1], rob1[i - 2] + nums[i]);
        }
        rob2[0] = 0;
        rob2[1] = nums[1];
        rob2[2] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); ++i) {
            rob2[i] = max(rob2[i - 1], rob2[i - 2] + nums[i]);
        }
        return max(rob1[nums.size() - 2], rob2[nums.size() - 1]);

    }
};
