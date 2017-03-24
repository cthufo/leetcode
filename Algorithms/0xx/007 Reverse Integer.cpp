class Solution {
public:
    //  c++ -> a / b * b + a % b = a, a % b = a - a / b * b;
    int reverse(int x) {
        long long answer = 0, temp = x;
        while (temp) {
            answer = answer * 10 + temp % 10;
            temp /= 10;
        }
        return (answer > INT_MAX || answer < INT_MIN) ? 0 : (int)answer;
    }
};
