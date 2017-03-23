class Solution {
public:
    void getAnswers(vector<int>& nums, int target, vector<int>& answer, vector<vector<int>>& answers) {
        for (int i = 1; i < nums.size(); i++) {
            answer[1] = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                answer[2] = nums[j];
                for (int l = 0, r = nums.size() - 1, sum = answer[1] + answer[2]; l < i && r > j; l++, r--) {
                    int temp = nums[l] + nums[r];
                    if (sum + temp == target) {
                        answer[0] = nums[l];
                        answer[3] = nums[r];
                        answers.push_back(answer);
                    } else if (sum + temp > target) {
                        l--;
                    } else {
                        r++;
                    }
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> answer(4);
        vector<vector<int>> answers;
        sort(nums.begin(), nums.end());
        getAnswers(nums, target, answer, answers);
        sort(answers.begin(), answers.end(), [](const vector<int>& l, const vector<int>& r) {
            for (int i = 0; i < 4; i++) {
                if (l[i] < r[i]) {
                    return true;
                } else if (l[i] > r[i]) {
                    return false;
                }
            }
            return false;
        });
        for (int i = 0; i < answers.size(); i++) {
            for (auto it = answers.begin() + i + 1; it < answers.end(); it++) {
                if (answers[i] != *it) {
                    break;
                }
                it = answers.erase(it) - 1;
            }
        }
        return answers;
    }
};
