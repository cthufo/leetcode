int gcd(int x, int y)
{
	return y == 0 ? (x == 0 ? 1 : x) : (x % y == 0 ? y : gcd(y, x % y));
}

bool canMeasureWater(int x, int y, int z) {
	int g = gcd(x > y ? x : y, x > y ? y : x);
	return (z % g == 0 && x + y >= z);
}


