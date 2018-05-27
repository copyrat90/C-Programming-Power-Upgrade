#include <stdio.h>
#include <string.h>

#define STR_LEN 20
#define STR_NUM 4
#define TOTAL_STR_LEN (STR_LEN * STR_NUM)

int main(void)
{
	int i, j;
	char *pszTmp;
	char szInput1[STR_LEN + 1];
	char szInput2[STR_LEN + 1];
	char szInput3[STR_LEN + 1];
	char szInput4[STR_LEN + 1];

	char szResult[TOTAL_STR_LEN + STR_NUM + 1] = { 0 };
	char* pszInputs[STR_NUM] = { szInput1, szInput2, szInput3, szInput4 };

	// ���ڿ� �Է��� szInputX �� ���� ����
	for (i = 0; i < STR_NUM; i++)
	{
		printf("���ڿ� �Է� %d : ", i + 1);
		gets_s(pszInputs[i], STR_LEN + 1);
	}

	// pszInputs ������ �迭�� ������ �迭 ������ �ǵ��� ��������
	// strcmp() �Լ� �̿�
	for (i = STR_NUM - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (strcmp(pszInputs[j], pszInputs[j + 1]) > 0)
			{
				pszTmp = pszInputs[j];
				pszInputs[j] = pszInputs[j + 1];
				pszInputs[j + 1] = pszTmp;
			}

	// szResult �迭�� pszInputs �迭 ������� ���ڿ� ����
	// strcat() �Լ� �̿�
	for (i = 0; i < STR_NUM; i++)
	{
		strcat_s(szResult, sizeof(szResult), pszInputs[i]);
		strcat_s(szResult, sizeof(szResult), " ");
	}

	fputs("���ĵ� ���ڿ� : ", stdout);
	puts(szResult);

	return 0;
}