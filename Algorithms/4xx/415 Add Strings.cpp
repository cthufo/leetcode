class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string answer = "";
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; i--, j--, c /= 10) {
            c += (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
            answer = (char)('0' + c % 10) + answer;
        }
        return c ? (char)('0' + c % 10) + answer : answer;
    }
};
