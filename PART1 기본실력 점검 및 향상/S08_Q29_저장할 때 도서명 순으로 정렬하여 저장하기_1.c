#include <stdio.h>
#include <string.h>

#define BOOK_COUNT 3
#define STR_LEN 50

typedef struct __bookInfo
{
	char szTitle[STR_LEN];
	char szPub[STR_LEN];
	int nPrice;
} bookInfo;

void bookInfoInput(bookInfo *pbookInfo);
void ArrSortNSave(bookInfo *bIArr, const bookInfo *bIBuff);

int main(void)
{
	int i;
	bookInfo bookInfoBuff;
	bookInfo bookInfoArr[BOOK_COUNT] = { 0 };

	puts("********* 도서 정보 입력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 입력.\n", i + 1);
		
		bookInfoInput(&bookInfoBuff);
		ArrSortNSave(bookInfoArr, &bookInfoBuff);

		printf("%d번째 입력 완료.......\n\n", i + 1);
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

void bookInfoInput(bookInfo *pbookInfo)
{
	fputs("도서 제목 : ", stdout);
	gets_s(pbookInfo->szTitle, STR_LEN);
	fputs("출판사 명 : ", stdout);
	gets_s(pbookInfo->szPub, STR_LEN);
	fputs("도서 가격 : ", stdout);
	scanf_s("%d", &pbookInfo->nPrice);

	while (getchar() != '\n');
	return;
}

// 배열을 돌며 제목이 앞선 인덱스를 발견하면 배열을 뒤로 밀고 삽입
void ArrSortNSave(bookInfo *bIArr, const bookInfo *bIBuff)
{
	int i, j;
	for (i = 0; i < BOOK_COUNT; i++)
	{
		// i번 요소가 비어있다면
		if (strcmp((bIArr + i)->szTitle, "") == 0)
		{
			// i번 인덱스에 삽입
			memcpy_s(bIArr + i, sizeof(bookInfo), bIBuff, sizeof(bookInfo));
			break;
		}

		if (strcmp((bIArr + i)->szTitle, bIBuff->szTitle) == 1)
		{
			// 배열 요소를 한 칸씩 뒤로 이동시키기
			for (j = BOOK_COUNT - 1; j > i; j--)
				memcpy_s(bIArr + j, sizeof(bookInfo), bIArr + j - 1, sizeof(bookInfo));
			
			// i번 인덱스에 삽입
			memcpy_s(bIArr + i, sizeof(bookInfo), bIBuff, sizeof(bookInfo));

			break;
		}
	}

	return;
}