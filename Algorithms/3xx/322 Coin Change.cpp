class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        int * table = new int[amount + 1];
        table[0] = 0;
        for (int i = 1; i <= amount; i++) {
            table[i] = INT_MAX;
            for (int j = 0; j < size; j++) {
                int k = i - coins[j];
                if (k < 0) continue;
                table[i] = table[k] != INT_MAX ? min(table[k] + 1, table[i]) : table[i];
            }
        }
        int answer = table[amount] == INT_MAX ? -1 : table[amount];
        delete[] table;
        return answer;
    }
};
