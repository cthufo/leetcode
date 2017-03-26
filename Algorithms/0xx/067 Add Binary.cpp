class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string answer = "";
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--, c /= 2) {
            c += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            answer = (char)('0' + c % 2) + answer;
        }
        return c ? (char)('0' + c % 2) + answer : answer;
    }
};
