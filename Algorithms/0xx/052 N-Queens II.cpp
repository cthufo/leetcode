class Solution {
public:
    int n = 0, count = 0;
    bool isAvailableQueen(vector<int>& queens, int i, int index) {
        for (int j = 0; j < queens.size(); j++) {
            if (queens[j] == i || abs(queens[j] - i) == abs(j - index)) {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<int>& queens, int index) {
        if (index == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isAvailableQueen(queens, i, index)) {
                queens.push_back(i);
                DFS(queens, index + 1);
                queens.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> d;
        this->n = n;
        vector<int> queens;
        DFS(queens, 0);
        return count;
    }
};
