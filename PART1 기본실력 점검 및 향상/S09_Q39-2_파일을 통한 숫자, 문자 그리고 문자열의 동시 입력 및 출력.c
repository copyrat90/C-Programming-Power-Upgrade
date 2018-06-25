#include <stdio.h>
#define STR_MAX 100

int main(void)
{
	int nBuff;
	char szBuff[STR_MAX] = { 0 }, chBuff;

	FILE *fp = NULL;
	fopen_s(&fp, "weather.txt", "r");
	if (fp == NULL)
	{
		puts("���� 'weather.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}
	
	while (1)
	{
		fread_s(&nBuff, sizeof(nBuff), sizeof(int), 1, fp);
		if (feof(fp) != 0) // ������ ���� fread_s() ���� �Ŀ��� ����� ���� ����
			break;

		fprintf(stdout, "��¥ : %d", nBuff);
		fputc('\n', stdout);

		fputs("���� : ", stdout);
		fgets(szBuff, STR_MAX - 1, fp);
		fputs(szBuff, stdout);

		fputs("����(A)/����(P) : ", stdout);
		chBuff = fgetc(fp);
		fputc(chBuff, stdout);
		fputc('\n', stdout);

		fputs("���� : ", stdout);
		fgets(szBuff, STR_MAX - 1, fp);
		fputs(szBuff, stdout);

		fputc('\n', stdout);
	}

	fclose(fp);
	puts("����� �Ϸ�Ǿ����ϴ�.");
	return 0;
}