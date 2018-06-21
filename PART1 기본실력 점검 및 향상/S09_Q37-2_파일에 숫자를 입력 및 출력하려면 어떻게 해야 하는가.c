#include <stdio.h>
#define NUM_LEN 5

int main(void)
{
	int nRead, i;

	FILE *fp = NULL;
	fopen_s(&fp, "numeric.dat", "rb");

	if (fp == NULL)
	{
		puts("파일 'numeric.dat'가 열리지 않았습니다.");
		return -1;
	}
	
	for (i = 0; i < NUM_LEN; i++)
	{
		fread_s(&nRead, sizeof(nRead), sizeof(int), 1, fp);
		printf("%d 번째 입력 된 숫자 : %d\n", i + 1, nRead);
	}

	fclose(fp);
	puts("출력이 완료되었습니다.");

	return 0;
}