bool canConstruct(char* ransomNote, char* magazine) {
	bool flag = true;
	int count[256] = {0};
	int magazineLen = strlen(magazine), ransomNoteLen = strlen(ransomNote);
	for (int i = 0; i < magazineLen; i++) {
		count[magazine[i]]++;
	}
	for (int i = 0; i < ransomNoteLen && flag; i++) {
		count[ransomNote[i]]--;
		if (count[ransomNote[i]] < 0) {
			flag = false;
		}
	}
	return flag;
}
