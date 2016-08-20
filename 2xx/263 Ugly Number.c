bool isUgly(int num) {
	int index = 0, primes[3] = {2, 3, 5};
	while (index < 3 && num) {
		if (num % primes[index]) {
			index++;
		} else {
			num =  num / primes[index];
		}
	}
	return num == 1;
}