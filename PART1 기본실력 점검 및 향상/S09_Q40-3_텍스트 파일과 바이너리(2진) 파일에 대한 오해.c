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

	fputs("���� �̸� : ", stdout);
	gets_s(szOrigin, sizeof(szOrigin));

	fopen_s(&fpOrigin, szOrigin, "rb");
	if (fpOrigin == NULL)
	{
		printf("���� ���� '%s'�� ������ �ʾҽ��ϴ�.\n", szOrigin);
		return -1;
	}

	fputs("���纻 �̸� : ", stdout);
	gets_s(szCopy, sizeof(szCopy));

	fopen_s(&fpCopy, szCopy, "wb");
	if (fpCopy == NULL)
	{
		printf("���纻 ���� '%s'�� ������ �ʾҽ��ϴ�.\n", szCopy);
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
				puts("���� �߻�! ���縦 �Ϸ����� ���߽��ϴ�.");
				return -1;
			}
	}

	_fcloseall();

	puts("���簡 �Ϸ�Ǿ����ϴ�.");
	return 0;
}