#include <stdio.h>

void PrintSum(int *, int);
int ArrSum(int *, int);

int main(void)
{
	int arr1[3] = { 5, 10, 15 };
	int arr2[5] = { 1, 2, 3, 4, 5 };

	// 함수 내에서는 배열의 길이를 계산할 수 없다.
	// sizeof(pnArr) 은 포인터의 크기를 반환할 뿐이다.
	PrintSum(arr1, sizeof(arr1)/sizeof(int));
	PrintSum(arr2, sizeof(arr2)/sizeof(int));

	return 0;
}

void PrintSum(int *pnArr, int nLen)
{
	for (int i = 0; i < nLen - 1; i++)
		printf("%d, ", pnArr[i]);
	printf("%d의 합 : %d\n", pnArr[nLen - 1], ArrSum(pnArr, nLen));

	return;
}

int ArrSum(int *pnArr, int nLen)
{
	int nSum = 0;
	for (int i = 0; i < nLen; i++)
		nSum += pnArr[i];

	return nSum;
}