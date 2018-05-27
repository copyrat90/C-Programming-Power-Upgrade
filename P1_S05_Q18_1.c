#include <stdio.h>
#include <string.h>

#define STR_LEN 20
#define STR_NUM 4
#define TOTAL_STR_LEN (STR_LEN * STR_NUM)

int main(void)
{
	int i, j, k;
	char *pszTmp;
	char szInput1[STR_LEN + 1];
	char szInput2[STR_LEN + 1];
	char szInput3[STR_LEN + 1];
	char szInput4[STR_LEN + 1];

	char szResult[TOTAL_STR_LEN + STR_NUM + 1];
	char* pszInputs[STR_NUM] = { szInput1, szInput2, szInput3, szInput4 };

	// ���ڿ� �Է��� szInputX �� ���� ����
	for (i = 0; i < STR_NUM; i++)
	{
		printf("���ڿ� �Է� %d : ", i + 1);
		gets_s(pszInputs[i], STR_LEN + 1);
	}

	// pszInputs ������ �迭�� ������ �迭 ������ �ǵ��� ��������
	// å ����� strcmp() �Լ� �̿�
	for (i = STR_NUM - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			for (k = 0; k < STR_LEN; k++)
				if (pszInputs[j][k] > pszInputs[j + 1][k])
				{
					pszTmp = pszInputs[j];
					pszInputs[j] = pszInputs[j + 1];
					pszInputs[j + 1] = pszTmp;
					break;
				}
				else if (pszInputs[j][k] < pszInputs[j + 1][k])
					break;

	// szResult �迭�� pszInputs �迭 ������� ���ڿ� ����
	// å ����� strcat() �Լ� �̿�
	char *pszOffset = szResult;
	for (i = 0; i < STR_NUM; i++)
	{
		strcpy_s(pszOffset, STR_LEN + 1, pszInputs[i]);
		pszOffset += strlen(pszInputs[i]);
		strcpy_s(pszOffset, 2, " ");
		pszOffset++;
	}

	fputs("���ĵ� ���ڿ� : ", stdout);
	puts(szResult);

	return 0;
}