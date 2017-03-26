class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        for (int i = 0, count = 0; i < nums.size(); i++) {
            count = nums[i] == 1 ? count + 1 : 0;
            max = max > count ? max : count;
        }
        return max;
    }
};
