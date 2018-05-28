#include <stdio.h>
#define STR_MAX 100

int strLen(char *str);
int strCpy(char *dest, char *source);
int strCat(char *dest, char *source);
int strCmp(char *str1, char *str2);

int main(void)
{
	char str1[STR_MAX + 1] = "Good morning?";
	char str2[STR_MAX + 1] = "HaHaHa!";
	char buffString[STR_MAX + 1];

	// strLen test
	printf("length of \"%s\" : %d\n", str1, strLen(str1));
	printf("length of \"%s\" : %d\n", str2, strLen(str2));

	// strCpy test
	strCpy(buffString, str1);
	printf("copy string : \"%s\"\n", buffString);

	// strCat test
	strCat(buffString, str2);
	printf("concat string : \"%s\"\n", buffString);

	// strCmp test
	printf("cmp str1, str1 : %d\n", strCmp(str1, str1));
	printf("cmp str2, str2 : %d\n", strCmp(str2, str2));
	printf("cmp str1, str2 : %d\n", strCmp(str1, str2));
	printf("cmp str2, str1 : %d\n", strCmp(str2, str1));

	return 0;
}

// å���� *str != 0 ���� ���ǰ˻� �� nCount++; ���ٰ�
// str++; �� �����͸� ���� ���ڷ� �̵�
int strLen(char *str)
{
	int nCount = 0;
	while (str[nCount] != '\0')
		nCount++;

	return nCount;
}

int strCpy(char *dest, char *source)
{
	// �� ���ڱ��� �����ϱ� ����
	// nLen �� �� ���ڱ��� ������ ���̷� ����
	int nLen = strLen(source) + 1;
	for (int i = 0; i < nLen; i++)
		dest[i] = source[i];
	
	return nLen;
}

int strCat(char *dest, char *source)
{
	int nDstLen = strLen(dest);

	// dest �� ���� �� ���� ��ġ�� source �� ����
	return nDstLen + strCpy(dest + nDstLen, source);
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