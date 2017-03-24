/*
Symbol	I	V	X	L	C	D	M
Value	1	5	10	50	100	500	1,000
*/
int romanToInt(char* s) {
	int len = strlen(s), table[26] = {0};
	table['I' - 'A'] = 1;
	table['V' - 'A'] = 5;
	table['X' - 'A'] = 10;
	table['L' - 'A'] = 50;
	table['C' - 'A'] = 100;
	table['D' - 'A'] = 500;
	table['M' - 'A'] = 1000;
	int sum = table[s[0] - 'A'];
	for (int i = 1; i < len; i++) {
		sum += table[s[i] - 'A'];
		if (table[s[i - 1] - 'A'] < table[s[i] - 'A']) {
			sum -= table[s[i - 1] - 'A'] * 2;
		}
	}
	return sum;
}