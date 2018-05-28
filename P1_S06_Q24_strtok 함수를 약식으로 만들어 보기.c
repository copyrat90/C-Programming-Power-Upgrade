#include <stdio.h>

char* StringTokenize(char *, char *);

int main(void)
{
	char pszPhone[] = "010-1122-3333";
	char *pszDel = "-";
	char *pToken;

	pToken = StringTokenize(pszPhone, pszDel);
	while (pToken != NULL)
	{
		puts(pToken);
		pToken = StringTokenize(NULL, pszDel);
	}

	return 0;
}


char* StringTokenize(char *pszString, char *pszDelimiter)
{
	static char *pNextToken = NULL;
	char *pToken = NULL;

	// 인자1 이 NULL이면 기존 pNextToken을 그대로 사용
	if (pszString == NULL)
	{
		// 다음 토큰이 NULL이면 문자열의 끝이라는 의미이므로 NULL 반환
		if (pNextToken == NULL)
			return NULL;
		// 아니라면 계산을 위해 현재 토큰을 다음 토큰에서 가져옴
		else
			pToken = pNextToken;
	}
	else
		// 인자1 이 NULL이 아니면
		// 문자열의 첫 주소를 pToken과 pNextToken에 저장
	{
		pToken = pszString;
		pNextToken = pszString;
	}

	// *pNextToken 이 구분자와 같다면 널 문자로 바꾸고 한 칸 더 이동
	while (1)
	{
		pNextToken++;

		// 구분자에 도달하면 널 문자로 바꾸고 한 칸 더 가서 탈출
		if (*pNextToken == *pszDelimiter)
		{
			*pNextToken++ = '\0';
			break;
		}
		// 문자열의 끝에 도달하면 pNextToken에 NULL 넣고 탈출
		else if (*pNextToken == '\0')
		{
			pNextToken = NULL;
			break;
		}
	}
	
	return pToken;
}