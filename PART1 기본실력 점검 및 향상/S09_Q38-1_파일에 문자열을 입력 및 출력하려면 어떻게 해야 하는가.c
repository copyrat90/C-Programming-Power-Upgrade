#include <stdio.h>
#define STR_MAX 100
#define DATA_CNT 5

int main(void)
{
	char szBuff[STR_MAX] = { 0 };
	int i;
	
	FILE *fp = NULL;
	fopen_s(&fp, "string.txt", "w");
	if (fp == NULL)
	{
		puts("���� 'string.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (i = 0; i < DATA_CNT; i++)
	{
		printf("%d ��° ���ڿ� �Է� : ", i + 1);
		fgets(szBuff, STR_MAX - 1, stdin); // NULL ���� 100����, ������ 99����
		fputs(szBuff, fp);
	}

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	return 0;
}