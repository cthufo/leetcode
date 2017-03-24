int pow10(int n) {
	if (n == 0) {
		return 1;
	} else if (n % 2) {
		int product = pow10(n / 2);
		return 10 * product * product;
	} else {
		int product = pow10(n / 2);
		return product * product;
	}
}

void bucketSort(unsigned int * nums, int numsSize) {
	bool flag = true;
	int * buckets[10] = {0}, bucketsCount[10] = {0}, round = 1;
	for (int i = 0; i < 10; i++) {
		buckets[i] = malloc(sizeof(int) * numsSize);
	}
	for (int i = 0; i < numsSize; i++) {
		nums[i] = (int)nums[i] >= 0 ? nums[i] + 2147483648 : nums[i] - 2147483648;
	}
	while (flag) {
		flag = false;
		for (int i = 0; i < numsSize; i++) {
			int index = nums[i] % pow10(round) / pow10(round - 1) ;
			buckets[index][bucketsCount[index]++] = nums[i];
			if (index) {
				flag = true;
			}
		}
		for (int i = 0, count = 0; i < 10; i++) {
			for (int j = 0; j < bucketsCount[i]; j++) {
				nums[count++] = buckets[i][j];
			}
			bucketsCount[i] = 0;
		}
		round++;
	}
	for (int i = 0; i < 10; i++) {
		free(buckets[i]);
	}
	for (int i = 0; i < numsSize; i++) {
		nums[i] = (int)nums[i] >= 0 ? nums[i] - 2147483648 : nums[i] + 2147483648;
	}
}

bool containsDuplicate(int* nums, int numsSize) {
	bool flag = false;
	bucketSort((unsigned int *)nums, numsSize);
	for (int i = 1; i < numsSize && !flag; i++) {
		if (nums[i - 1] == nums[i]) {
			flag = true;
		}
	}
	return flag;
}