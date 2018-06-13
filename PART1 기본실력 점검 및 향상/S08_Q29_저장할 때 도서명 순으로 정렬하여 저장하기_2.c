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
int InsertArr(bookInfo *bIArr, const bookInfo *bIBuff);

int main(void)
{
	int i, nReturn;
	bookInfo bookInfoBuff;
	bookInfo bookInfoArr[BOOK_COUNT] = { 0 };

	puts("********* ���� ���� �Է� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		
		bookInfoInput(&bookInfoBuff);
		nReturn = InsertArr(bookInfoArr, &bookInfoBuff);

		if (nReturn == -1)
			puts("�Է¿� �����Ͽ����ϴ�.\n");
		else
			printf("%d��° �Է� �Ϸ�.......\n\n", i + 1);
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

void bookInfoInput(bookInfo *pbookInfo)
{
	fputs("���� ���� : ", stdout);
	gets_s(pbookInfo->szTitle, STR_LEN);
	fputs("���ǻ� �� : ", stdout);
	gets_s(pbookInfo->szPub, STR_LEN);
	fputs("���� ���� : ", stdout);
	scanf_s("%d", &pbookInfo->nPrice);

	while (getchar() != '\n');
	return;
}

// �迭�� ���� ������ �ռ� �ε����� �߰��ϸ� �迭�� �ڷ� �а� ����
int InsertArr(bookInfo *bIArr, const bookInfo *bIBuff)
{
	static int ArrCount = 0;
	int i = 0, j;

	if (ArrCount >= BOOK_COUNT)
		return -1;

	for (i = 0; i < ArrCount; i++)
		if (strcmp(bIArr[i].szTitle, bIBuff->szTitle) > 0)
		{
			// �迭 ��Ҹ� �� ĭ�� �ڷ� �̵���Ű��
			// i�� �ε����� �� �� �ֵ��� �ϴ� ��
			for (j = ArrCount; j > i; j--)
				bIArr[j] = bIArr[j - 1];
			break;
		}

	// i�� �ε����� ����
	bIArr[i] = *bIBuff;

	// �迭�� �ϳ� ä�����Ƿ� ���� ���� ArrCount �� 1 ����
	return ++ArrCount;
}