class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        int size = A.size(), count = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int key = C[i] + D[j];
                if (hash.find(key) == hash.end()) {
                    hash[key] = 0;
                }
                hash[key]++;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int key = 0 - (A[i] + B[j]);
                if (hash.find(key) != hash.end()) {
                    count += hash[key];
                }
            }
        }
        return count;
    }
};
