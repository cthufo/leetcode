int climbStairs(int n) {
	int f[3] = {1, 1, 0};
	for (int i = 2; i <= n; i++) {
		f[1] = f[2] = f[0] + f[1];
		f[0] = f[1] - f[0];
	}
	return n < 2 ? f[n] : f[2];
}