class Solution {
public:
    int pow2(int n) {
        if (n == 0) {
            return 1;
        }
        int answer = pow2(n / 2);
        return answer * answer * (n % 2 == 1 ? 2 : 1);
    }
    int findComplement(int num) {
        int i = 0, answer = 0;
        for (; num > 0; num /= 2, i++) {
            answer += pow2(i) * !(num % 2);
        }
        return answer;
    }
};
