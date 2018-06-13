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

	puts("********* ���� ���� �Է� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		
		bookInfoInput(&bIBuff);
		nReturn = InsertArr(bIArr, &bIBuff);

		if (nReturn == -1)
			puts("�Է¿� �����Ͽ����ϴ�.\n");
		else
			printf("%d��° �Է� �Ϸ�.......\n\n", i + 1);
	}

	pabISortInit(pabISort, bIArr);
	
	while (1)
	{
		puts("********* ���� ���� ��� *********");
		puts("���Ĺ�� ����......");
		puts("1. ���� ���� ��, 2. ���ǻ� ��, 3. ���� ��, 4. ����");
		fputs("�״��� ������? ", stdout);
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
	fputs("���� ���� : ", stdout);
	gets_s(pbI->szTitle, STR_LEN);
	fputs("���ǻ� �� : ", stdout);
	gets_s(pbI->szPub, STR_LEN);
	fputs("���� ���� : ", stdout);
	scanf_s("%d", &pbI->nPrice);

	while (getchar() != '\n');
	return;
}

// �迭�� ���� ������ �ռ� �ε����� �߰��ϸ� �迭�� �ڷ� �а� ����
int InsertArr(bookInfo *bIArr, const bookInfo *bIBuff)
{
	static int ArrCount = 0;
	int iInsert = 0, j;

	if (ArrCount >= BOOK_COUNT)
		return -1;

	// ������� iInsert ���
	for (iInsert = 0; iInsert < ArrCount; iInsert++)
		if (strcmp(bIArr[iInsert].szTitle, bIBuff->szTitle) > 0)
			break;
	
	// �迭 ��Ҹ� �� ĭ�� �ڷ� �̵���Ű��
	// iInsert�� �ε����� �� �� �ֵ��� �ϴ� ��
	for (j = ArrCount; j > iInsert; j--)
		bIArr[j] = bIArr[j - 1];

	// iInsert�� �ε����� ����
	bIArr[iInsert] = *bIBuff;

	// �迭�� �ϳ� ä�����Ƿ� ���� ���� g_ArrCount �� 1 ����
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
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ���� : %s\n", ppabISort[i]->szTitle);
		printf("���ǻ� �� : %s\n", ppabISort[i]->szPub);
		printf("���� ���� : %d\n\n", ppabISort[i]->nPrice);
	}
}