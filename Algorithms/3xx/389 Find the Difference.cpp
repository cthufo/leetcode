class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']--;
            count[t[i] - 'a']++;
        }
        count[t[t.length() - 1] - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (count[i]) return i + 'a';
        }
        return 0;
    }
};
