#include <stdio.h>
#define STR_MAX 100
#define DATA_CNT 5

void PrintLine(FILE *fp, int nChoice);
void PrintAll(FILE *fp);

int main(void)
{
	int nChoice = 0;

	FILE *fp = NULL;
	fopen_s(&fp, "string.txt", "r");
	if (fp == NULL)
	{
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	printf("출력할 문자열 정보 입력(%d이상은 전체 출력) : ", DATA_CNT + 1);
	scanf_s("%d", &nChoice);

	if (0 < nChoice && nChoice <= DATA_CNT)
		PrintLine(fp, nChoice);
	else if (nChoice > DATA_CNT)
		PrintAll(fp);
	else
		puts("적절치 않은 입력!");

	fclose(fp);
	puts("출력이 완료되었습니다.");

	return 0;
}

void PrintLine(FILE *fp, int nChoice)
{
	char szBuff[STR_MAX] = { 0 };
	for (int i = 0; i < nChoice; i++)
		fgets(szBuff, STR_MAX - 1, fp);
	fputs(szBuff, stdout);
}

void PrintAll(FILE *fp)
{
	char szBuff[STR_MAX] = { 0 };

	while (1)
	{
		fgets(szBuff, STR_MAX - 1, fp);
		// feof 함수는 파일의 끝에 도달했을 때 0이 아닌 값을 반환
		// 마지막 문자가 개행문자면 파일의 끝은 한 번 더 fgets() 시 확인함
		if (feof(fp) != 0)
			break;
		fputs(szBuff, stdout);

#ifdef _DEBUG
		printf("feof(fp) == %d, ftell(fp) == %d\n", feof(fp), ftell(fp));
#endif
	}
}