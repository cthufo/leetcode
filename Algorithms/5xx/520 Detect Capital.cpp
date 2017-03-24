class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = word.length() && isalpha(word[0]);
        for (int i = 1; i < word.length() && flag; flag = word[i] >= 'a' && word[i] <= 'z', i++);
        if (flag) return flag; else flag = word.length() && (word[0] >= 'A' && word[0] <= 'Z');
        for (int i = 1; i < word.length() && flag; flag = word[i] >= 'A' && word[i] <= 'Z', i++);
        return flag; 
    }
};
