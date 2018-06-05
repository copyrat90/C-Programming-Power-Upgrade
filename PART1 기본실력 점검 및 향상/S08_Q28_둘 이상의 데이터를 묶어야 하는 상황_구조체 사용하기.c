#include <stdio.h>

#define BOOK_COUNT 3
#define STR_LEN 50

typedef struct __bookInfo
{
	char szTitle[STR_LEN];
	char szPub[STR_LEN];
	int nPrice;
} bookInfo;

int main(void)
{
	int i;
	bookInfo bookInfoArr[BOOK_COUNT];

	puts("********* ���� ���� �Է� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets_s(bookInfoArr[i].szTitle, STR_LEN);
		fputs("���ǻ� �� : ", stdout);
		gets_s(bookInfoArr[i].szPub, STR_LEN);
		fputs("���� ���� : ", stdout);
		scanf_s("%d", &bookInfoArr[i].nPrice);
		printf("%d��° �Է� �Ϸ�.......\n\n", i + 1);

		while (getchar() != '\n');
	}

	puts("********* ���� ���� ��� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� ���.\n", i+1);
		printf("���� ���� : %s\n", bookInfoArr[i].szTitle);
		printf("���ǻ� �� : %s\n", bookInfoArr[i].szPub);
		printf("���� ���� : %d\n\n", bookInfoArr[i].nPrice);
	}

	return 0;
}