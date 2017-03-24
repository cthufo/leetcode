#define swap(x, y) { x = x ^ y; y = x ^ y; x = x ^ y; }
void quickSort(int left, int right, int * nums)
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
		}
	}
	if (left - 1 != piviot) {
        swap(nums[left - 1], nums[piviot]);
    }
	quickSort(piviot, left - 1, nums);
	quickSort(left, end, nums);
}
	
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int largeIndex = 0, largeSize = nums1Size > nums2Size ? nums1Size : nums2Size;
    int smallIndex = 0, smallSize = nums1Size > nums2Size ? nums2Size : nums1Size;
	int * returnNums = malloc(sizeof(int) * smallSize);
    int * smallNums = nums1Size > nums2Size ? nums2 : nums1, * largeNums = nums1Size > nums2Size ? nums1 : nums2;
	*returnSize = 0;
	quickSort(0, smallSize, smallNums);
	quickSort(0, largeSize, largeNums);
	while (smallIndex < smallSize && largeIndex < largeSize) {
		if (smallNums[smallIndex] < largeNums[largeIndex]) {
			smallIndex++;
		} else if (smallNums[smallIndex] > largeNums[largeIndex]) {
			largeIndex++;
		} else {
			if ((*returnSize) - 1 < 0 || returnNums[(*returnSize) - 1] != smallNums[smallIndex]) {
				returnNums[(*returnSize)++] = smallNums[smallIndex];
            }
			largeIndex++;
			smallIndex++;
		}
	}
	return returnNums;
}