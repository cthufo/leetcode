class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer(2);
        for (int i = 0, s = 0, j = numbers.size() - 1; i < j; i += s < target, j -= s > target) {
            s = numbers[i] + numbers[j];
            if (s == target) {
                answer[0] = i + 1, answer[1] = j + 1;
                return answer;
            }
        }
        return answer;
    }
};
