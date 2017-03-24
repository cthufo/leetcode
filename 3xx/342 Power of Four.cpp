class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((1073741824 % num == 0 && (0xAAAAAAAA ^ num | num) != 0xAAAAAAAA));
    }
};
