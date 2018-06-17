// 책에선 *str != 0 으로 조건검사 후 nCount++; 에다가
// str++; 로 포인터를 다음 문자로 이동
int strLen(char *str)
{
	int nCount = 0;
	while (str[nCount] != '\0')
		nCount++;

	return nCount;
}

int strCmp(char *str1, char *str2)
{
	char ch1, ch2;
	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		ch1 = str1[i];
		// 대문자나 소문자나 사전상 같은 위치이므로
		// 소문자를 대문자로 바꿔 비교
		if ('a' <= ch1 && ch1 <= 'z')
			ch1 += -'a' + 'A';
		ch2 = str2[i];
		if ('a' <= ch2 && ch2 <= 'z')
			ch2 += -'a' + 'A';

		if (ch1 < ch2)
			return -1;
		else if (ch1 > ch2)
			return 1;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	// str1 이 먼저 끝났으면 사전 상 앞쪽
	else if (str1[i] == '\0')
		return -1;
	else
		return 1;
}