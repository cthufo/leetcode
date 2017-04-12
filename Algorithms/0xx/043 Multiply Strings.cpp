class Solution {
public:
    string multiply(string num, char c, int n) {
        if (c == '0') return "";
        int carry = 0;
        string answer(n, '0');
        for (int i = num.length() - 1, temp = 0; i >= 0; i--) {
            temp = (num[i] - '0') * (c - '0') + carry;
            carry = temp / 10;
            answer = (char)(temp % 10 + '0') + answer;
        }
        return carry ? (char)(carry + '0') + answer : answer;
    }
    
    string add(string num1, string num2) {
        string answer = "";
        int len1 = num1.length(), len2 = num2.length(), temp = 0, carry = 0;
        while (len1 > 0 || len2 > 0) {
            len1--, len2--;
            temp = carry;
            temp += len1 >= 0 ? num1[len1] - '0' : 0;
            temp += len2 >= 0 ? num2[len2] - '0' : 0;
            carry = temp / 10;
            answer = (char)(temp % 10 + '0') + answer;
        }
        return carry ? (char)(carry + '0') + answer : answer;
    }
    
    string multiply(string num1, string num2) {
        if ((num1.length() == 1 && num1[0] == '0') || (num2.length() == 1 && num2[0] == '0')) return "0";
        string result = "";
        int len1 = num1.length(), len2 = num2.length();
        for (int i = len2 - 1; i >= 0; i--) {
            result = add(result, multiply(num1, num2[i], len2 - 1 - i));
        }
        return result;
    }
};
