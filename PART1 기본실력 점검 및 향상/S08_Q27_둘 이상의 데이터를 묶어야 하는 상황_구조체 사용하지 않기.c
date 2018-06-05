#include <stdio.h>

#define BOOK_COUNT 3
#define STR_LEN 50

int main(void)
{
	int i;
	char szaBookName[BOOK_COUNT][STR_LEN] = { 0 };
	char szaPublisher[BOOK_COUNT][STR_LEN] = { 0 };
	int naPrice[BOOK_COUNT] = { 0 };

	puts("********* 도서 정보 입력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets_s(szaBookName[i], STR_LEN);
		fputs("출판사 명 : ", stdout);
		gets_s(szaPublisher[i], STR_LEN);
		fputs("도서 가격 : ", stdout);
		scanf_s("%d", naPrice + i);
		printf("%d번째 입력 완료.......\n\n", i + 1);

		while (getchar() != '\n');
	}

	puts("********* 도서 정보 출력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 출력.\n", i+1);
		printf("도서 제목 : %s\n", szaBookName[i]);
		printf("출판사 명 : %s\n", szaPublisher[i]);
		printf("도서 가격 : %d\n\n", naPrice[i]);
	}

	return 0;
}