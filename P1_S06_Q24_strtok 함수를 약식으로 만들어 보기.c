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

	// ����1 �� NULL�̸� ���� pNextToken�� �״�� ���
	if (pszString == NULL)
	{
		// ���� ��ū�� NULL�̸� ���ڿ��� ���̶�� �ǹ��̹Ƿ� NULL ��ȯ
		if (pNextToken == NULL)
			return NULL;
		// �ƴ϶�� ����� ���� ���� ��ū�� ���� ��ū���� ������
		else
			pToken = pNextToken;
	}
	else
		// ����1 �� NULL�� �ƴϸ�
		// ���ڿ��� ù �ּҸ� pToken�� pNextToken�� ����
	{
		pToken = pszString;
		pNextToken = pszString;
	}

	// *pNextToken �� �����ڿ� ���ٸ� �� ���ڷ� �ٲٰ� �� ĭ �� �̵�
	while (1)
	{
		pNextToken++;

		// �����ڿ� �����ϸ� �� ���ڷ� �ٲٰ� �� ĭ �� ���� Ż��
		if (*pNextToken == *pszDelimiter)
		{
			*pNextToken++ = '\0';
			break;
		}
		// ���ڿ��� ���� �����ϸ� pNextToken�� NULL �ְ� Ż��
		else if (*pNextToken == '\0')
		{
			pNextToken = NULL;
			break;
		}
	}
	
	return pToken;
}