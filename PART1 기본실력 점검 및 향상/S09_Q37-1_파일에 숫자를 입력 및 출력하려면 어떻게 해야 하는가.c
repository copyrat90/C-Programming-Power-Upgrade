#include <stdio.h>
#define NUM_LEN 5

int main(void)
{
	int nInput, i;

	FILE *fp = NULL;
	fopen_s(&fp, "numeric.dat", "wb");

	if (fp == NULL)
	{
		puts("���� 'numeric.dat'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}
	
	for (i = 0; i < NUM_LEN; i++)
	{
		printf("���Ͽ� ������ ���� %d : ", i + 1);
		scanf_s("%d", &nInput);
		fwrite(&nInput, sizeof(int), 1, fp);
	}

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	return 0;
}