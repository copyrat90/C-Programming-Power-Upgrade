#include <stdio.h>
#define NUM_LEN 5

int main(void)
{
	int nInput, i;

	FILE *fp = NULL;
	fopen_s(&fp, "numeric.dat", "wb");

	if (fp == NULL)
	{
		puts("파일 'numeric.dat'가 열리지 않았습니다.");
		return -1;
	}
	
	for (i = 0; i < NUM_LEN; i++)
	{
		printf("파일에 저장할 숫자 %d : ", i + 1);
		scanf_s("%d", &nInput);
		fwrite(&nInput, sizeof(int), 1, fp);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");

	return 0;
}