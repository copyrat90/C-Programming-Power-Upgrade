#include "myString.h"

int strCpy(char *dest, char *source)
{
	// 널 문자까지 복사하기 위해
	// nLen 을 널 문자까지 포함한 길이로 설정
	int nLen = strLen(source) + 1;
	for (int i = 0; i < nLen; i++)
		dest[i] = source[i];

	return nLen;
}

int strCat(char *dest, char *source)
{
	int nDstLen = strLen(dest);

	// dest 의 끝인 널 문자 위치에 source 를 복사
	return nDstLen + strCpy(dest + nDstLen, source);
}