#include <stdio.h>

#define BOOK_COUNT 3
#define STR_LEN 50

int main(void)
{
	int i;
	char szaBookName[BOOK_COUNT][STR_LEN] = { 0 };
	char szaPublisher[BOOK_COUNT][STR_LEN] = { 0 };
	int naPrice[BOOK_COUNT] = { 0 };

	puts("********* ���� ���� �Է� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets_s(szaBookName[i], STR_LEN);
		fputs("���ǻ� �� : ", stdout);
		gets_s(szaPublisher[i], STR_LEN);
		fputs("���� ���� : ", stdout);
		scanf_s("%d", naPrice + i);
		printf("%d��° �Է� �Ϸ�.......\n\n", i + 1);

		while (getchar() != '\n');
	}

	puts("********* ���� ���� ��� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� ���.\n", i+1);
		printf("���� ���� : %s\n", szaBookName[i]);
		printf("���ǻ� �� : %s\n", szaPublisher[i]);
		printf("���� ���� : %d\n\n", naPrice[i]);
	}

	return 0;
}