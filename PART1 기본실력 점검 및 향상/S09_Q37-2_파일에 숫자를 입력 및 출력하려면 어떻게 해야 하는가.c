#include <stdio.h>
#define NUM_LEN 5

int main(void)
{
	int nRead, i;

	FILE *fp = NULL;
	fopen_s(&fp, "numeric.dat", "rb");

	if (fp == NULL)
	{
		puts("���� 'numeric.dat'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}
	
	for (i = 0; i < NUM_LEN; i++)
	{
		fread_s(&nRead, sizeof(nRead), sizeof(int), 1, fp);
		printf("%d ��° �Է� �� ���� : %d\n", i + 1, nRead);
	}

	fclose(fp);
	puts("����� �Ϸ�Ǿ����ϴ�.");

	return 0;
}