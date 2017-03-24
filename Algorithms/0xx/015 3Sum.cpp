class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> answer(3);
        vector<vector<int>> answers;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            answer[0] = nums[i];
            for (int l = i + 1, r = nums.size() - 1, sum = nums[i]; r > l; l++, r--) {
                int temp = nums[l] + nums[r];
                if (sum + temp == 0) {
                    answer[1] = nums[l], answer[2] = nums[r];
                    if (answers.size() && answers[answers.size() - 1] == answer) {
                        continue;
                    }
                    answers.push_back(answer);
                } else if (sum + temp < 0) {
                    r++;
                } else {
                    l--;
                }
            }
        }
        return answers;
    }
};
