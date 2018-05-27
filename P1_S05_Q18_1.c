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

	// 문자열 입력해 szInputX 에 각각 저장
	for (i = 0; i < STR_NUM; i++)
	{
		printf("문자열 입력 %d : ", i + 1);
		gets_s(pszInputs[i], STR_LEN + 1);
	}

	// pszInputs 포인터 배열이 사전식 배열 순서가 되도록 버블정렬
	// 책 답안은 strcmp() 함수 이용
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

	// szResult 배열에 pszInputs 배열 순서대로 문자열 쓰기
	// 책 답안은 strcat() 함수 이용
	char *pszOffset = szResult;
	for (i = 0; i < STR_NUM; i++)
	{
		strcpy_s(pszOffset, STR_LEN + 1, pszInputs[i]);
		pszOffset += strlen(pszInputs[i]);
		strcpy_s(pszOffset, 2, " ");
		pszOffset++;
	}

	fputs("정렬된 문자열 : ", stdout);
	puts(szResult);

	return 0;
}