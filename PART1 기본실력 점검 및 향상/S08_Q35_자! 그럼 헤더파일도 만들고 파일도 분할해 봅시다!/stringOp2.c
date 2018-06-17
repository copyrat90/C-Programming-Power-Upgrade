#include "myString.h"

int strCpy(char *dest, char *source)
{
	// �� ���ڱ��� �����ϱ� ����
	// nLen �� �� ���ڱ��� ������ ���̷� ����
	int nLen = strLen(source) + 1;
	for (int i = 0; i < nLen; i++)
		dest[i] = source[i];

	return nLen;
}

int strCat(char *dest, char *source)
{
	int nDstLen = strLen(dest);

	// dest �� ���� �� ���� ��ġ�� source �� ����
	return nDstLen + strCpy(dest + nDstLen, source);
}