#include <stdio.h>

int main(void)
{
	// fgetc()가 반환하는 4바이트 EOF를 받기 위해 chBuff는 int 형으로 선언한다.
	// char 형으로 선언하면 0xFF 가 되는데 이게 데이터인지 EOF인지 알 수 없다.
	// int 형으로 선언해야 데이터인 0x000000FF 와 EOF인 0xFFFFFFFF 를 구분할 수 있다.
	int i, nChCount, chBuff;

	FILE *fp = fopen("character.txt", "r");
	if (fp == NULL)
	{
		puts("파일 'character.txt'가 열리지 않았습니다.");
		return -1;
	}

	printf("출력할 문자의 개수는? ");
	scanf_s("%d", &nChCount);

	for (i = 0; i < 2 * nChCount; i++)
	{
		chBuff = fgetc(fp);
		if (chBuff == EOF)
		{
			puts("\n파일의 끝에 도달하여 출력을 일찍 끝냈습니다.");
			break;
		}
		else
			fputc(chBuff, stdout);
	}

	fclose(fp);

	puts("\n출력이 완료되었습니다.");
	return 0;
}