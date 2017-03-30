class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] > 0 ? nums[i] : 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i] < 0 ? nums[i] ^ INT_MIN : nums[i];
            if (value >= 1 && value <= nums.size()) {
                nums[value - 1] = nums[value - 1] | INT_MIN;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) return i + 1;
        }
        return nums.size() + 1;
    }
};
