int getSum(int a, int b) {
	while (a & b) {
		a = a ^ b;
		b = ((a ^ b) & b) << 1;
	}
	return a ^ b;
}
