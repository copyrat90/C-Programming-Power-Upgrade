#include <stdio.h>

int main(void)
{
	char szInput[] = { "가나다라마바사아자차카타파하" };
	int i;

	FILE *fp = fopen("character.txt", "w");
	if (fp == NULL)
	{
		puts("파일 'character.txt'가 열리지 않았습니다.");
		return -1;
	}

	for (i = 0; i < sizeof(szInput) - 1; i++)
		fputc(szInput[i], fp);

	fclose(fp);

	puts("입력이 완료되었습니다.");
	return 0;
}