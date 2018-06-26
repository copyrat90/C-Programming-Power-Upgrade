#include <stdio.h>
#include <string.h>
#define STR_MAX 100
#define READ_BLOCK 1024 // 1 kb

int main(void)
{
	int nReadCnt;
	char szBuff[READ_BLOCK];
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
		nReadCnt = fread_s(szBuff, sizeof(szBuff), sizeof(char), READ_BLOCK, fpOrigin);
		fwrite(szBuff, sizeof(char), nReadCnt, fpCopy);
		if (nReadCnt < READ_BLOCK)
			if (feof(fpOrigin) != 0)
				break;
			else
			{
				puts("오류 발생! 복사를 완료하지 못했습니다.");
				return -1;
			}
	}

	_fcloseall();

	puts("복사가 완료되었습니다.");
	return 0;
}