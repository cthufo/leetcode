class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ** table = new int * [grid.size() + 2];
        for (int i = 0; i < grid.size() + 2; i++) {
            table[i] = new int[grid[0].size() + 2];
            memset(table[i], 0x00, (grid[0].size() + 2) * sizeof(int)); 
            if (i >= 1 && i <= grid.size()) {
                memcpy(table[i] + 1, grid[i - 1].data(), grid[i - 1].size() * sizeof(int)); 
            }
        }
        int count = 0;
        for (int i = 1; i <= grid.size(); i++) {
            for (int j = 1; j <= grid[i - 1].size(); j++) {
                count = count + table[i][j] * (4 - (table[i - 1][j] + table[i + 1][j] + table[i][j - 1] + table[i][j + 1]));
            }
        }
        return count;
    }
};
