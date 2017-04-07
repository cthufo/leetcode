class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length(), needleLength = needle.length();
        for (int i = 0; i + needleLength <= haystackLength; i++) {
            bool flag = true;
            for (int j = 0; j < needleLength && flag; j++) {
                flag = haystack[i + j] == needle[j];
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};
