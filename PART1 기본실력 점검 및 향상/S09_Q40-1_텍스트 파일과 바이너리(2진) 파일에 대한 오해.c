#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int main(void)
{
	char sz1[STR_MAX] = { 0 };
	char sz2[STR_MAX] = { 0 };
	int i = 0;

	FILE *fp = NULL;
	// �ؽ�Ʈ ���� ���� ���������Ƿ� \n �� �� �� �ڵ����� \r\n ���� �ٲ� ����.
	fopen_s(&fp, "string.txt", "w");
	if (fp == NULL)
	{
		puts("���� 'string.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	puts("------- ���ڿ� �Է� �� ���� ---------");
	fputs("ù ��° ���ڿ� : ", stdout);
	fgets(sz1, STR_MAX - 2, stdin);
	fputs("�� ��° ���ڿ� : ", stdout);
	fgets(sz2, STR_MAX - 2, stdin);

	// string.txt �� sz1, sz2 ����
	fwrite(sz1, sizeof(char), strlen(sz1), fp);
	fwrite(sz2, sizeof(char), strlen(sz2), fp);

	// ���� �ݾҴ� ����
	fclose(fp);
	fp = NULL;
	// �ؽ�Ʈ �б� ���� ���������Ƿ� \r\n�� ���� �� �ڵ����� \n ���� �ٲ� �д´�.
	fopen_s(&fp, "string.txt", "r");
	if (fp == NULL)
	{
		puts("���� 'string.txt'�� �б� ���� �ٽ� ���� �� �����߽��ϴ�.");
		return -1;
	}

	// ���Ͽ��� sz1, sz2 �ٽ� �������� ���� �ݱ�
	// fread_s()�� \n�� �Ϲ� ���ڷ� �о���� �� ���ھ� �о� \n �ǵ� �ʿ�
	for (i = 0;; i++)
	{
		fread_s(sz1 + i, sizeof(sz1) - i, sizeof(char), 1, fp);
		if (sz1[i] == '\n')
		{
			sz1[i + 1] = '\0';
			break;
		}
	}
	for (i = 0;; i++)
	{
		fread_s(sz2 + i, sizeof(sz2) - i, sizeof(char), 1, fp);
		if (sz2[i] == '\n')
		{
			sz2[i + 1] = '\0';
			break;
		}
	}
	fclose(fp);

	puts("\n------- ����� ���ڿ� ��� ----------");
	printf("ù ��° ���ڿ� : %s", sz1);
	printf("�� ��° ���ڿ� : %s", sz2);

	return 0;
}