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
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	for (i = 0; i < DATA_CNT; i++)
	{
		printf("%d 번째 문자열 입력 : ", i + 1);
		fgets(szBuff, STR_MAX - 1, stdin); // NULL 포함 100글자, 미포함 99글자
		fputs(szBuff, fp);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");

	return 0;
}