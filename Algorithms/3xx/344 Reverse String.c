char* reverseString(char* s) {
	int len = strlen(s);
	char * str = malloc(len + 1);
	for (int i = 0; i < len; i++) {
		str[i] = s[len - i - 1];
	}
	str[len] = '\0';
	return str;
}
