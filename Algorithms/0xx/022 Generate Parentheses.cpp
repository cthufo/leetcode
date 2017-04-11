class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        int size = 0, lsize = 0, rsize = 0;
        string data(2 * n, '.');
        do {
            if (size == 2 * n) {
                parenthesis.push_back(data);
                size = lsize + rsize;
                while (size && (data[size - 1] != '(' || (rsize + 1) >= lsize)) {
                    data[size-- - 1] == '(' ? lsize-- : rsize--;
                }
                if (size) {
                    data[size - 1] = ')';
                    lsize--, rsize++;
                }
            } else if (lsize < n) {
                data[lsize++ + rsize] = '(';
            } else if (lsize == n) {
                data[lsize + rsize++] = ')';
            }
            size = lsize + rsize;
        } while (size);
        return parenthesis;

    }
};
