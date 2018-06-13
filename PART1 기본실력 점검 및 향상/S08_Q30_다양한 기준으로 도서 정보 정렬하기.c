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

enum {SORT_TITLE = 1, SORT_PUB, SORT_PRICE, EXIT};

void bookInfoInput(bookInfo *pbI);
int InsertArr(bookInfo *bIArr, const bookInfo *bIBuff);
void pabISortInit(bookInfo* *ppabISort, bookInfo *pbIArr);

void SortByTitle(bookInfo* *ppabISort, bookInfo *pbIArr);
void SortByPub(bookInfo* *ppabISort);
void SortByPrice(bookInfo* *ppabISort);

void PrintArr(bookInfo* *ppabISort);

int main(void)
{
	int i, nReturn, nChoice;
	bookInfo bIBuff;
	bookInfo bIArr[BOOK_COUNT] = { 0 };
	bookInfo* pabISort[BOOK_COUNT] = { 0 };

	puts("********* 도서 정보 입력 *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 입력.\n", i + 1);
		
		bookInfoInput(&bIBuff);
		nReturn = InsertArr(bIArr, &bIBuff);

		if (nReturn == -1)
			puts("입력에 실패하였습니다.\n");
		else
			printf("%d번째 입력 완료.......\n\n", i + 1);
	}

	pabISortInit(pabISort, bIArr);
	
	while (1)
	{
		puts("********* 도서 정보 출력 *********");
		puts("정렬방식 선택......");
		puts("1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료");
		fputs("그대의 선택은? ", stdout);
		scanf_s("%d", &nChoice);

		if (nChoice == EXIT)
			break;

		switch (nChoice)
		{
		case SORT_TITLE:
			SortByTitle(pabISort, bIArr);
			PrintArr(pabISort);
			break;

		case SORT_PUB:
			SortByPub(pabISort);
			PrintArr(pabISort);
			break;

		case SORT_PRICE:
			SortByPrice(pabISort);
			PrintArr(pabISort);
			break;
		}
	}

	return 0;
}

void bookInfoInput(bookInfo *pbI)
{
	fputs("도서 제목 : ", stdout);
	gets_s(pbI->szTitle, STR_LEN);
	fputs("출판사 명 : ", stdout);
	gets_s(pbI->szPub, STR_LEN);
	fputs("도서 가격 : ", stdout);
	scanf_s("%d", &pbI->nPrice);

	while (getchar() != '\n');
	return;
}

// 배열을 돌며 제목이 앞선 인덱스를 발견하면 배열을 뒤로 밀고 삽입
int InsertArr(bookInfo *bIArr, const bookInfo *bIBuff)
{
	static int ArrCount = 0;
	int iInsert = 0, j;

	if (ArrCount >= BOOK_COUNT)
		return -1;

	// 집어넣을 iInsert 계산
	for (iInsert = 0; iInsert < ArrCount; iInsert++)
		if (strcmp(bIArr[iInsert].szTitle, bIBuff->szTitle) > 0)
			break;
	
	// 배열 요소를 한 칸씩 뒤로 이동시키기
	// iInsert번 인덱스에 쓸 수 있도록 하는 것
	for (j = ArrCount; j > iInsert; j--)
		bIArr[j] = bIArr[j - 1];

	// iInsert번 인덱스에 삽입
	bIArr[iInsert] = *bIBuff;

	// 배열을 하나 채웠으므로 정적 변수 g_ArrCount 를 1 증가
	return ++ArrCount;
}

void pabISortInit(bookInfo* *ppabISort, bookInfo *pbIArr)
{
	for (int i = 0; i < BOOK_COUNT; i++)
		ppabISort[i] = pbIArr + i;
}

void SortByTitle(bookInfo* *ppabISort, bookInfo *pbIArr)
{
	pabISortInit(ppabISort, pbIArr);
}

void SortByPub(bookInfo* *ppabISort)
{
	bookInfo *bIBuff;
	int i, j;
	for (i = 0; i<BOOK_COUNT - 1; i++)
		for (j = i + 1; j<BOOK_COUNT; j++)
			if (strcmp(ppabISort[i]->szPub, ppabISort[j]->szPub) > 0)
			{
				bIBuff = ppabISort[i];
				ppabISort[i] = ppabISort[j];
				ppabISort[j] = bIBuff;
			}
}

void SortByPrice(bookInfo* *ppabISort)
{
	bookInfo *bIBuff;
	int i, j;
	for (i = 0; i<BOOK_COUNT - 1; i++)
		for (j = i + 1; j<BOOK_COUNT; j++)
			if (ppabISort[i]->nPrice > ppabISort[j]->nPrice)
			{
				bIBuff = ppabISort[i];
				ppabISort[i] = ppabISort[j];
				ppabISort[j] = bIBuff;
			}
}

void PrintArr(bookInfo* *ppabISort)
{
	for (int i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목 : %s\n", ppabISort[i]->szTitle);
		printf("출판사 명 : %s\n", ppabISort[i]->szPub);
		printf("도서 가격 : %d\n\n", ppabISort[i]->nPrice);
	}
}