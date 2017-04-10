class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int ** DP = new int * [m + 1];
        for (int i = 0; i <= m; i++) {
            DP[i] = new int[n + 1];
            for (int j = 0; j <= n; j++) {
                DP[i][j] = INT_MAX;
            }
        }
        DP[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                DP[i][j] = min(DP[i][j + 1], DP[i + 1][j]) - dungeon[i][j];
                DP[i][j] = DP[i][j] > 0 ? DP[i][j] : 1;
            }
        }
        int answer = DP[0][0];
        for (int i = 0; i <= m; i++) {
            delete[] DP[i];
        }
        delete[] DP;
        return answer;
    }
};
