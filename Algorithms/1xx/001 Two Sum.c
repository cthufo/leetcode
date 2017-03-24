#define swap(x, y) { x = x ^ y; y = x ^ y; x = x ^ y; }
void quickSort(int left, int right, int * nums, int * indices)
{
	if (right - left <= 1) {
		return;
	}
	int piviot = left, end = right;
	while (left < right) {
		while (left < right && nums[++left] < nums[piviot]);
		while (left < right && nums[--right] > nums[piviot]);
		if (left != right) {
			swap(nums[left], nums[right]);
			swap(indices[left], indices[right]);
		}
	}
	if (left - 1 != piviot) {
		swap(nums[left - 1], nums[piviot]);
		swap(indices[left - 1], indices[piviot]);
	}
	quickSort(piviot, left - 1, nums, indices);
	quickSort(left, end, nums, indices);
}

int binarySearch(int left, int right, int * nums, int target) {
	if (left > right) {
		return 0;
	}
	int mid = (left + right) / 2;
	if (target == nums[mid]) {
		return mid;
	} else if (target < nums[mid]) {
		return binarySearch(left, mid - 1, nums, target);
	}
	return  binarySearch(mid + 1, right, nums, target);
}

int* twoSum(int* nums, int numsSize, int target) {
	int * ans = malloc(2 * sizeof(int));
	int * indices = malloc(numsSize * sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		indices[i] = i;
	}
	quickSort(0, numsSize, nums, indices);
	for (int i = 0; i < numsSize; i++) {
		int j = binarySearch(i + 1, numsSize, nums, target - nums[i]);
		if (j > i) {
			ans[0] = indices[j] > indices[i] ? indices[i] : indices[j];
			ans[1] = indices[j] > indices[i] ? indices[j] : indices[i];
			break;
		}
	}
	return ans;
}