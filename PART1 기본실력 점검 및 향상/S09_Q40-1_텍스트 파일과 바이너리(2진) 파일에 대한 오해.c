#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int main(void)
{
	char sz1[STR_MAX] = { 0 };
	char sz2[STR_MAX] = { 0 };
	int i = 0;

	FILE *fp = NULL;
	// 텍스트 쓰기 모드로 개방했으므로 \n 을 쓸 때 자동으로 \r\n 으로 바꿔 쓴다.
	fopen_s(&fp, "string.txt", "w");
	if (fp == NULL)
	{
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	puts("------- 문자열 입력 및 저장 ---------");
	fputs("첫 번째 문자열 : ", stdout);
	fgets(sz1, STR_MAX - 2, stdin);
	fputs("두 번째 문자열 : ", stdout);
	fgets(sz2, STR_MAX - 2, stdin);

	// string.txt 에 sz1, sz2 쓰기
	fwrite(sz1, sizeof(char), strlen(sz1), fp);
	fwrite(sz2, sizeof(char), strlen(sz2), fp);

	// 파일 닫았다 열기
	fclose(fp);
	fp = NULL;
	// 텍스트 읽기 모드로 개방했으므로 \r\n을 읽을 때 자동으로 \n 으로 바꿔 읽는다.
	fopen_s(&fp, "string.txt", "r");
	if (fp == NULL)
	{
		puts("파일 'string.txt'를 읽기 모드로 다시 여는 데 실패했습니다.");
		return -1;
	}

	// 파일에서 sz1, sz2 다시 꺼내오고 파일 닫기
	// fread_s()는 \n도 일반 문자로 읽어오니 한 글자씩 읽어 \n 판독 필요
	for (i = 0;; i++)
	{
		fread_s(sz1 + i, sizeof(sz1) - i, sizeof(char), 1, fp);
		if (sz1[i] == '\n')
		{
			sz1[i + 1] = '\0';
			break;
		}
	}
	for (i = 0;; i++)
	{
		fread_s(sz2 + i, sizeof(sz2) - i, sizeof(char), 1, fp);
		if (sz2[i] == '\n')
		{
			sz2[i + 1] = '\0';
			break;
		}
	}
	fclose(fp);

	puts("\n------- 저장된 문자열 출력 ----------");
	printf("첫 번째 문자열 : %s", sz1);
	printf("두 번째 문자열 : %s", sz2);

	return 0;
}