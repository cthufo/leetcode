class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size(), maxSum = INT_MIN, maxValue = INT_MIN, count = 0;
        int * dp = new int[size + 1];
        dp[0] = 0;
        for (int i = 1; i <= size; i++) {
            count += nums[i - 1] < 0;
            if (count == i) maxValue = max(maxValue, nums[i - 1]);
            dp[i] = max(0, dp[i - 1] + nums[i - 1]);
            maxSum = max(maxSum, dp[i]);
        }
        delete[] dp;
        return count == size ? maxValue : maxSum;
    }
};
