#include <stdio.h>
#include <string.h>

#define STR_MAX 100

// strlen() �Լ� �̿�
int StrFind(char *pStr, char ch)
{
	int nCount = 0;
	int nLen = strlen(pStr);

	for (int i = 0; i < nLen; i++)
		if (pStr[i] == ch)
			nCount++;

	return nCount;
}

int main(void)
{
	char szString[STR_MAX + 1] = { 0 };
	char ch2find;

	fputs("��� ���ڿ� �Է� : ", stdout);
	gets_s(szString, sizeof(szString));
	fputs("���� �� ���� �Է� : ", stdout);
	ch2find = getchar();

	printf("%c�� ���� : %d\n", ch2find, StrFind(szString, ch2find));

	return 0;
}