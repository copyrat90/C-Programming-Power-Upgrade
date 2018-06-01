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
		printf("문자열 입력 %d : ", i + 1);
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
		// realloc 실패로 문자열이 정상적으로 입력되지 않았으면
		else
			puts("[오류 난 문자열]");
	}

	return 0;
}

// char* * 를 쓰는 이유는 들어오는 char* 의 값을 수정할 필요가 있기 때문
int ExtendMem(char* *pszOld, int nOldLen)
{
	// EXT_SIZE 만큼 늘린 크기로 realloc()
	// 한 개씩 늘리면 ExtendMem() 이 너무 자주 호출되어 성능이 하락하기 때문에 EXT_SIZE 는 적당한 크기로
	char *pszNew = (char*)realloc(*pszOld, nOldLen + EXT_SIZE);

	// realloc 성공하면 기존 주소를 새 주소로 대치 후 새 크기 반환
	if (pszNew != NULL)
	{
		*pszOld = pszNew;
		return nOldLen + EXT_SIZE;
	}
	// realloc 실패하면 기존 주소 해제 후 NULL로 만들고 0 반환
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
	// 일단 EXT_SIZE 크기의 메모리 동적 할당
	char *psz = (char*)malloc(EXT_SIZE * sizeof(char));
	*psz = '\0';
	char chBuff;

	// 글자수가 메모리 크기를 넘으면 ExtendMem() 호출하여 글자 수 EXT_SIZE개 더 늘림
	while ((chBuff = getchar()) != '\n')
	{
		psz[nIndex++] = chBuff;
		// 인덱스가 nLen 과 같거나 커지면 메모리 크기를 늘림
		if (nIndex >= nLen)
			nLen = ExtendMem(&psz, nLen);
		// nLen 이 0이면 realloc 오류가 발생한 것이므로 NULL 반환
		if (nLen == 0)
			return NULL;
		
		// 문자열의 끝은 항상 '\0'
		psz[nIndex] = '\0';
	}

	return psz;
}

// strlen(NULL) 은 작동 정지되니 NULL이 들어오면 0을 반환하는 함수 정의
int MyStrlen(char *psz)
{
	if (psz != NULL)
		return strlen(psz);
	else
		return 0;
}

// 길이가 짧은 순으로 버블정렬
// realloc 실패 문자열은 MyStrlen() 에서 0 반환되므로 제일 앞으로 온다.
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