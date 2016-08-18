int pow26(int n) {
	if (n == 0) {
		return 1;
	} else if (n % 2) {
		int product = pow26(n / 2);
		return 26 * product * product;
	} else {
		int product = pow26(n / 2);
		return product * product;
	}
}

int titleToNumber(char* s) {
	int number = 0, len = strlen(s) - 1;
	for (int i = len; i >= 0; i--) {
		number += (toupper(s[i]) - 'A' + 1) * pow26(len - i);
	}
	return number;
}