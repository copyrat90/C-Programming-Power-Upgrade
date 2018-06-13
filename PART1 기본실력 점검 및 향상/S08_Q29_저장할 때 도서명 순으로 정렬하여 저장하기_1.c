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

	puts("********* ���� ���� �Է� *********");
	for (i = 0; i < BOOK_COUNT; i++)
	{
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		
		bookInfoInput(&bookInfoBuff);
		ArrSortNSave(bookInfoArr, &bookInfoBuff);

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
void ArrSortNSave(bookInfo *bIArr, const bookInfo *bIBuff)
{
	int i, j;
	for (i = 0; i < BOOK_COUNT; i++)
	{
		// i�� ��Ұ� ����ִٸ�
		if (strcmp((bIArr + i)->szTitle, "") == 0)
		{
			// i�� �ε����� ����
			memcpy_s(bIArr + i, sizeof(bookInfo), bIBuff, sizeof(bookInfo));
			break;
		}

		if (strcmp((bIArr + i)->szTitle, bIBuff->szTitle) == 1)
		{
			// �迭 ��Ҹ� �� ĭ�� �ڷ� �̵���Ű��
			for (j = BOOK_COUNT - 1; j > i; j--)
				memcpy_s(bIArr + j, sizeof(bookInfo), bIArr + j - 1, sizeof(bookInfo));
			
			// i�� �ε����� ����
			memcpy_s(bIArr + i, sizeof(bookInfo), bIBuff, sizeof(bookInfo));

			break;
		}
	}

	return;
}