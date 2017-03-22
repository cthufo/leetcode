class Solution {
public:
    int myAtoi(string str) {
        int space = 0;
        while (space < str.length() && str[space] == ' ') space++;
        bool sign = space < str.length() && (str[space] == '-' || str[space] == '+');
        unsigned int i = space + sign, p = 1, sum = 0;
        for (; i < str.length() && isdigit(str[i]) && !(p * 10 % 10 && p != 1); i++, p *= 10);
        for (p /= isdigit(str[i]) ? 1 : 10, i = space + sign; i < str.length() && isdigit(str[i]); i++, p /= 10) {
            sum += p * (str[i] - '0');
            if (sum > INT_MAX || p == 0) {
                return sign && str[space + sign - 1] == '-' ? INT_MIN : INT_MAX;
            }
        }
        return sum * (sign && str[space + sign - 1] == '-' ? -1 : 1);
    }
};
