bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	int flag = 1, product = 1;
	while (x / product >= 10) {
		product *= 10;
	}
	while (x && flag) {
		int left = x / product, right = x % 10;
		x = x % product / 10;
		product = product / 100;
		flag = left == right;
	}
	return flag;
}