#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define STR_NUM 5
#define EXT_SIZE 5

void SortStringArr(char* *pszArr, int nLen);
char* GetString(void);

int main(void)
{
	char* pszArr[STR_NUM] = { 0 };
	int i;

	for (i = 0; i < STR_NUM; i++)
	{
		printf("���ڿ� �Է� %d : ", i + 1);
		pszArr[i] = GetString();
	}

	SortStringArr(pszArr, STR_NUM);

	for (i = 0; i < STR_NUM; i++)
	{
		if (pszArr[i] != NULL)
		{
			puts(pszArr[i]);
			free(pszArr[i]);
		}
		// realloc ���з� ���ڿ��� ���������� �Էµ��� �ʾ�����
		else
			puts("[���� �� ���ڿ�]");
	}

	return 0;
}

// char* * �� ���� ������ ������ char* �� ���� ������ �ʿ䰡 �ֱ� ����
int ExtendMem(char* *pszOld, int nOldLen)
{
	// EXT_SIZE ��ŭ �ø� ũ��� realloc()
	// �� ���� �ø��� ExtendMem() �� �ʹ� ���� ȣ��Ǿ� ������ �϶��ϱ� ������ EXT_SIZE �� ������ ũ���
	char *pszNew = (char*)realloc(*pszOld, nOldLen + EXT_SIZE);

	// realloc �����ϸ� ���� �ּҸ� �� �ּҷ� ��ġ �� �� ũ�� ��ȯ
	if (pszNew != NULL)
	{
		*pszOld = pszNew;
		return nOldLen + EXT_SIZE;
	}
	// realloc �����ϸ� ���� �ּ� ���� �� NULL�� ����� 0 ��ȯ
	else
	{
		free(*pszOld);
		*pszOld = NULL;
		return 0;
	}
}

char* GetString(void)
{
	int nIndex = 0, nLen = EXT_SIZE;
	// �ϴ� EXT_SIZE ũ���� �޸� ���� �Ҵ�
	char *psz = (char*)malloc(EXT_SIZE * sizeof(char));
	*psz = '\0';
	char chBuff;

	// ���ڼ��� �޸� ũ�⸦ ������ ExtendMem() ȣ���Ͽ� ���� �� EXT_SIZE�� �� �ø�
	while ((chBuff = getchar()) != '\n')
	{
		psz[nIndex++] = chBuff;
		// �ε����� nLen �� ���ų� Ŀ���� �޸� ũ�⸦ �ø�
		if (nIndex >= nLen)
			nLen = ExtendMem(&psz, nLen);
		// nLen �� 0�̸� realloc ������ �߻��� ���̹Ƿ� NULL ��ȯ
		if (nLen == 0)
			return NULL;
		
		// ���ڿ��� ���� �׻� '\0'
		psz[nIndex] = '\0';
	}

	return psz;
}

// strlen(NULL) �� �۵� �����Ǵ� NULL�� ������ 0�� ��ȯ�ϴ� �Լ� ����
int MyStrlen(char *psz)
{
	if (psz != NULL)
		return strlen(psz);
	else
		return 0;
}

// ���̰� ª�� ������ ��������
// realloc ���� ���ڿ��� MyStrlen() ���� 0 ��ȯ�ǹǷ� ���� ������ �´�.
void SortStringArr(char* *pszArr, int nLen)
{
	int i, j;
	char *pszTmp;

	for (i = 0; i < nLen - 1; i++)
		for (j = i; j < nLen; j++)
			if (MyStrlen(pszArr[i]) > MyStrlen(pszArr[j]))
			{
				pszTmp = pszArr[i];
				pszArr[i] = pszArr[j];
				pszArr[j] = pszTmp;
			}
}