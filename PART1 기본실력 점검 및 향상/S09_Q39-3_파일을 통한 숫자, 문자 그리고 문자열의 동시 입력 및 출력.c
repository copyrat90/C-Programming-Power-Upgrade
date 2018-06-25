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
		puts("파일 'weather.txt'가 열리지 않았습니다.");
		return -1;
	}

	fputs("검색할 날짜 및 지역 정보 입력 : ", stdout);
	// scanf_s() 는 %s 형식이 다름
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
			printf("날짜 : %d\n", nfDay);
			printf("지역 : %s", szfRegion);
			printf("오전(A)/오후(P) : %c\n", chfAM_PM);
			printf("날씨 : %s\n검색이 완료되었습니다.", szfWeather);

			return 0;
		}
	}

	fclose(fp);
	puts("\n해당 날짜 및 지역의 데이터가 존재하지 않습니다.");
	return 0;
}