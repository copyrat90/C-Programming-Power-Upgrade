#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int main(void)
{
	int nBuff = 0;
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
		nBuff = fgetc(fpOrigin);
		if (feof(fpOrigin) != 0)
			break;
		fputc(nBuff, fpCopy);
	}

	_fcloseall();

	puts("���簡 �Ϸ�Ǿ����ϴ�.");
	return 0;
}