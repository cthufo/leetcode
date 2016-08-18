int lengthOfLastWord(char* s) {
	int len = strlen(s), wordLen = 0;
	while (len--) {
		if (s[len] == ' ' && wordLen) {
			break;
		} else if (s[len] != ' ') {
			wordLen++;
		}
	}
	return wordLen;
}