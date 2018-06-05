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

	puts("********* 도서 정보 입력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets_s(bookInfoArr[i].szTitle, STR_LEN);
		fputs("출판사 명 : ", stdout);
		gets_s(bookInfoArr[i].szPub, STR_LEN);
		fputs("도서 가격 : ", stdout);
		scanf_s("%d", &bookInfoArr[i].nPrice);
		printf("%d번째 입력 완료.......\n\n", i + 1);

		while (getchar() != '\n');
	}

	puts("********* 도서 정보 출력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 출력.\n", i+1);
		printf("도서 제목 : %s\n", bookInfoArr[i].szTitle);
		printf("출판사 명 : %s\n", bookInfoArr[i].szPub);
		printf("도서 가격 : %d\n\n", bookInfoArr[i].nPrice);
	}

	return 0;
}