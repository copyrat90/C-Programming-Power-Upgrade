#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int main(void)
{
	int nDay;
	char szRegion[STR_MAX];
	char chAM_PM;

	int nfDay;
	char szfRegion[STR_MAX], szfWeather[STR_MAX];
	char chfAM_PM;

	FILE *fp = NULL;
	fopen_s(&fp, "weather.txt", "r");
	if (fp == NULL)
	{
		puts("���� 'weather.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	fputs("�˻��� ��¥ �� ���� ���� �Է� : ", stdout);
	// scanf_s() �� %s ������ �ٸ�
	scanf("%d %s %c", &nDay, szRegion, &chAM_PM);

	strcat_s(szRegion, sizeof(char)*STR_MAX, "\n");

	while (1)
	{
		fread_s(&nfDay, sizeof(nfDay), sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		fgets(szfRegion, STR_MAX - 1, fp);
		chfAM_PM = fgetc(fp);
		fgets(szfWeather, STR_MAX - 1, fp);

		if (nDay == nfDay && strcmp(szRegion, szfRegion) == 0 && chAM_PM == chfAM_PM)
		{
			fclose(fp);
			printf("��¥ : %d\n", nfDay);
			printf("���� : %s", szfRegion);
			printf("����(A)/����(P) : %c\n", chfAM_PM);
			printf("���� : %s\n�˻��� �Ϸ�Ǿ����ϴ�.", szfWeather);

			return 0;
		}
	}

	fclose(fp);
	puts("\n�ش� ��¥ �� ������ �����Ͱ� �������� �ʽ��ϴ�.");
	return 0;
}