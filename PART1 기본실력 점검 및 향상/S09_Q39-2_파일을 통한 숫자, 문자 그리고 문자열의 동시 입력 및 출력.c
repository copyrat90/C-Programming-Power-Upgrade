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
		puts("파일 'weather.txt'가 열리지 않았습니다.");
		return -1;
	}
	
	while (1)
	{
		fread_s(&nBuff, sizeof(nBuff), sizeof(int), 1, fp);
		if (feof(fp) != 0) // 파일의 끝을 fread_s() 실행 후에야 제대로 감지 가능
			break;

		fprintf(stdout, "날짜 : %d", nBuff);
		fputc('\n', stdout);

		fputs("지역 : ", stdout);
		fgets(szBuff, STR_MAX - 1, fp);
		fputs(szBuff, stdout);

		fputs("오전(A)/오후(P) : ", stdout);
		chBuff = fgetc(fp);
		fputc(chBuff, stdout);
		fputc('\n', stdout);

		fputs("날씨 : ", stdout);
		fgets(szBuff, STR_MAX - 1, fp);
		fputs(szBuff, stdout);

		fputc('\n', stdout);
	}

	fclose(fp);
	puts("출력이 완료되었습니다.");
	return 0;
}