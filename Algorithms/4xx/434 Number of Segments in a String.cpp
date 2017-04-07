class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (flag & s[i] == ' ') {
                count++;
                flag = false;
            } else if (!flag && s[i] != ' ') {
                flag = true;
            }
        }
        count += flag;
        return count;
    }
};
