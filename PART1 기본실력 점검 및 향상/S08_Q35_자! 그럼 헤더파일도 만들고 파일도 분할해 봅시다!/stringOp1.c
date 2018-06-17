// å���� *str != 0 ���� ���ǰ˻� �� nCount++; ���ٰ�
// str++; �� �����͸� ���� ���ڷ� �̵�
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
		// �빮�ڳ� �ҹ��ڳ� ������ ���� ��ġ�̹Ƿ�
		// �ҹ��ڸ� �빮�ڷ� �ٲ� ��
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
	// str1 �� ���� �������� ���� �� ����
	else if (str1[i] == '\0')
		return -1;
	else
		return 1;
}