#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int main(void)
{
	int nBuff = 0;
	char szOrigin[STR_MAX], szCopy[STR_MAX];
	FILE *fpOrigin = NULL, *fpCopy = NULL;

	fputs("원본 이름 : ", stdout);
	gets_s(szOrigin, sizeof(szOrigin));

	fopen_s(&fpOrigin, szOrigin, "rb");
	if (fpOrigin == NULL)
	{
		printf("원본 파일 '%s'가 열리지 않았습니다.\n", szOrigin);
		return -1;
	}

	fputs("복사본 이름 : ", stdout);
	gets_s(szCopy, sizeof(szCopy));

	fopen_s(&fpCopy, szCopy, "wb");
	if (fpCopy == NULL)
	{
		printf("복사본 파일 '%s'가 열리지 않았습니다.\n", szCopy);
		return -1;
	}

	while (1)
	{
		nBuff = fgetc(fpOrigin);
		if (feof(fpOrigin) != 0)
			break;
		fputc(nBuff, fpCopy);
	}

	_fcloseall();

	puts("복사가 완료되었습니다.");
	return 0;
}