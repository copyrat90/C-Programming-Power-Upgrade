#include <stdio.h>

int main(void)
{
	char szInput[] = { "�����ٶ󸶹ٻ������īŸ����" };
	int i;

	FILE *fp = fopen("character.txt", "w");
	if (fp == NULL)
	{
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (i = 0; i < sizeof(szInput) - 1; i++)
		fputc(szInput[i], fp);

	fclose(fp);

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	return 0;
}