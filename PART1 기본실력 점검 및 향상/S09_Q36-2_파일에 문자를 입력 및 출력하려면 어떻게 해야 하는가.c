#include <stdio.h>

int main(void)
{
	// fgetc()�� ��ȯ�ϴ� 4����Ʈ EOF�� �ޱ� ���� chBuff�� int ������ �����Ѵ�.
	// char ������ �����ϸ� 0xFF �� �Ǵµ� �̰� ���������� EOF���� �� �� ����.
	// int ������ �����ؾ� �������� 0x000000FF �� EOF�� 0xFFFFFFFF �� ������ �� �ִ�.
	int i, nChCount, chBuff;

	FILE *fp = fopen("character.txt", "r");
	if (fp == NULL)
	{
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	printf("����� ������ ������? ");
	scanf_s("%d", &nChCount);

	for (i = 0; i < 2 * nChCount; i++)
	{
		chBuff = fgetc(fp);
		if (chBuff == EOF)
		{
			puts("\n������ ���� �����Ͽ� ����� ���� ���½��ϴ�.");
			break;
		}
		else
			fputc(chBuff, stdout);
	}

	fclose(fp);

	puts("\n����� �Ϸ�Ǿ����ϴ�.");
	return 0;
}