bool binarySearchSquare(unsigned int left, unsigned int right, int value)
{
	int mid = (left + right) / 2;
	if (left > right) {
		return false;
	} else if (mid * mid == value) {
		return true;
	} else if (mid * mid < value) {
		return binarySearchSquare(mid + 1, right, value);
	} else {
		return binarySearchSquare(1, mid - 1, value);
	}
}

bool isPerfectSquare(int num) {
	return binarySearchSquare(1, num, num);
}
