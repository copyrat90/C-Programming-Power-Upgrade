#include <stdio.h>
#define STR_MAX 100
#define DATA_CNT 5

void PrintLine(FILE *fp, int nChoice);
void PrintAll(FILE *fp);

int main(void)
{
	int nChoice = 0;

	FILE *fp = NULL;
	fopen_s(&fp, "string.txt", "r");
	if (fp == NULL)
	{
		puts("���� 'string.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	printf("����� ���ڿ� ���� �Է�(%d�̻��� ��ü ���) : ", DATA_CNT + 1);
	scanf_s("%d", &nChoice);

	if (0 < nChoice && nChoice <= DATA_CNT)
		PrintLine(fp, nChoice);
	else if (nChoice > DATA_CNT)
		PrintAll(fp);
	else
		puts("����ġ ���� �Է�!");

	fclose(fp);
	puts("����� �Ϸ�Ǿ����ϴ�.");

	return 0;
}

void PrintLine(FILE *fp, int nChoice)
{
	char szBuff[STR_MAX] = { 0 };
	for (int i = 0; i < nChoice; i++)
		fgets(szBuff, STR_MAX - 1, fp);
	fputs(szBuff, stdout);
}

void PrintAll(FILE *fp)
{
	char szBuff[STR_MAX] = { 0 };

	while (1)
	{
		fgets(szBuff, STR_MAX - 1, fp);
		// feof �Լ��� ������ ���� �������� �� 0�� �ƴ� ���� ��ȯ
		// ������ ���ڰ� ���๮�ڸ� ������ ���� �� �� �� fgets() �� Ȯ����
		if (feof(fp) != 0)
			break;
		fputs(szBuff, stdout);

#ifdef _DEBUG
		printf("feof(fp) == %d, ftell(fp) == %d\n", feof(fp), ftell(fp));
#endif
	}
}