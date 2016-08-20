bool isHappy(int n) {
	int p = 0, sum = 0;
	bool used[1000] = {0};
	while (!used[sum] && sum != 1) {
		used[sum] = true;
		p = sum = 0;
		while (n) {
			int digit = n % 10;
			n /= 10;
			sum += digit * digit;
		}
		n = sum;
	}
	return sum == 1;
}