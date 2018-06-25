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
		puts("파일 'weather.txt'가 열리지 않았습니다.");
		return -1;
	}

	while (1)
	{
		puts("** 날씨 정보 입력 *******");

		fputs("날짜 : ", stdout);
		nReturn = fscanf_s(stdin, "%d", &nDay);
		while (fgetc(stdin) != '\n');
		if (nReturn == EOF)
			break;
		fwrite(&nDay, sizeof(int), 1, fp);

		fputs("지역 : ", stdout);
		fgets(szBuff, STR_MAX - 1, stdin);
		fputs(szBuff, fp);

		fputs("오전(A)/오후(P) : ", stdout);
		chAM_PM = fgetc(stdin);
		while (fgetc(stdin) != '\n');
		fputc(chBuff, fp);

		fputs("날씨 : ", stdout);
		fgets(szBuff, STR_MAX - 1, stdin);
		fputs(szBuff, fp);

		fputc('\n', stdout);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");
	return 0;
}