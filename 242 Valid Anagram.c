bool isAnagram(char* s, char* t) {
	int count[26] = {0}, sLen = strlen(s), tLen = strlen(t);
	if (sLen != tLen) {
		return false;
	}
	for (int i = 0; i < sLen; i++) {
		count[s[i] - 'a']++;
	}
	for (int i = 0; i < tLen; i++) {
		if (--count[t[i] - 'a'] < 0) {
			return false;
		}
	}
	return true;
}