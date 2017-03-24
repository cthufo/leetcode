bool isPalindrome(char* s) {
	bool flag = true;
	int left = -1, right = strlen(s);
	while (left < right && flag) {
		while (left < right && (!isalpha(s[++left]) && !isdigit(s[left])));
		while (left < right && (!isalpha(s[--right]) && !isdigit(s[right])));
		if (left < right && tolower(s[left]) != tolower(s[right])) {
			flag = false;
		}
	}
	return flag;
}