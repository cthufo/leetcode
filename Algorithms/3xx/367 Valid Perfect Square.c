bool binarySearchSquare(unsigned int left, unsigned int right, int value)
{
	int mid = (left + right) / 2;
	if (left > right) {
		return false;
	} else if ((value / mid == mid) && (value % mid == 0)) {
		return true;
	} else if (mid <= value / mid) {
		return binarySearchSquare(mid + 1, right, value);
	} else {
		return binarySearchSquare(1, mid - 1, value);
	}
}

bool isPerfectSquare(int num) {
	return binarySearchSquare(1, num, num);
}