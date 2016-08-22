bool isIsomorphic(char* s, char* t) {
	int len = strlen(s);
	char map[2][256] = {0}, flag = 1;
	for (int i = 0; i < len && flag; i++) {
		map[0][s[i]] = map[0][s[i]] ? map[0][s[i]] : t[i];
		map[1][t[i]] = map[1][t[i]] ? map[1][t[i]] : s[i];
		flag = map[0][s[i]] == t[i] && map[1][t[i]] == s[i];
	}
	return flag;
}