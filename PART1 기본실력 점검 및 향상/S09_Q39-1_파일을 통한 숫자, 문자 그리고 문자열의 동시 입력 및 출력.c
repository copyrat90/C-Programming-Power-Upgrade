#include <stdio.h>
#define STR_MAX 100

int main(void)
{
	int nDay, nReturn;
	char chAM_PM;
	char szBuff[STR_MAX];

	FILE *fp = NULL;
	fopen_s(&fp, "weather.txt", "w");
	if (fp == NULL)
	{
		puts("���� 'weather.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	while (1)
	{
		puts("** ���� ���� �Է� *******");

		fputs("��¥ : ", stdout);
		nReturn = fscanf_s(stdin, "%d", &nDay);
		while (fgetc(stdin) != '\n');
		if (nReturn == EOF)
			break;
		fwrite(&nDay, sizeof(int), 1, fp);

		fputs("���� : ", stdout);
		fgets(szBuff, STR_MAX - 1, stdin);
		fputs(szBuff, fp);

		fputs("����(A)/����(P) : ", stdout);
		chAM_PM = fgetc(stdin);
		while (fgetc(stdin) != '\n');
		fputc(chBuff, fp);

		fputs("���� : ", stdout);
		fgets(szBuff, STR_MAX - 1, stdin);
		fputs(szBuff, fp);

		fputc('\n', stdout);
	}

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	return 0;
}