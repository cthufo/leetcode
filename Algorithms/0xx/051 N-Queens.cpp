class Solution {
public:
    int n = 0;
    bool isAvailableQueen(vector<int>& queens, int i, int index) {
        for (int j = 0; j < queens.size(); j++) {
            if (queens[j] == i || abs(queens[j] - i) == abs(j - index)) {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<vector<string>>& answers, vector<int>& queens, int index) {
        if (index == n) {
            string data(n, '.');
            vector<string> answer(n);
            for (int i = 0; i < queens.size(); i++) {
                data[queens[i]] ='Q';
                answer[i] = data;
                data[queens[i]] ='.';
            }
            answers.push_back(answer);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isAvailableQueen(queens, i, index)) {
                queens.push_back(i);
                DFS(answers, queens, index + 1);
                queens.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answers;
        this->n = n;
        vector<int> queens;
        DFS(answers, queens, 0);
        return answers;
    }
};
