#include <stdio.h>

int main(void)
{
	char szInput[] = { "�����ٶ󸶹ٻ������īŸ����" };
	char *pszCurr = szInput;

	FILE *fp = fopen("character.txt", "w");
	if (fp == NULL)
	{
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	while (*pszCurr != '\0')
		fputc(*pszCurr++, fp);

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	return 0;
}