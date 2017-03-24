uint32_t reverseBits(uint32_t n) {
	uint32_t p = 1, ans = 0;
	for (int i = 0; i < 32; i++) {
		int shift = 31 - i * 2;
		ans |= shift > 0 ? (n & p) << shift : (n & p) >> (-1 * shift);
		p = p << 1;
	}
	return ans;
}