#include <stdio.h>

void PrintSum(int *, int);
int ArrSum(int *, int);

int main(void)
{
	int arr1[3] = { 5, 10, 15 };
	int arr2[5] = { 1, 2, 3, 4, 5 };

	// �Լ� �������� �迭�� ���̸� ����� �� ����.
	// sizeof(pnArr) �� �������� ũ�⸦ ��ȯ�� ���̴�.
	PrintSum(arr1, sizeof(arr1)/sizeof(int));
	PrintSum(arr2, sizeof(arr2)/sizeof(int));

	return 0;
}

void PrintSum(int *pnArr, int nLen)
{
	for (int i = 0; i < nLen - 1; i++)
		printf("%d, ", pnArr[i]);
	printf("%d�� �� : %d\n", pnArr[nLen - 1], ArrSum(pnArr, nLen));

	return;
}

int ArrSum(int *pnArr, int nLen)
{
	int nSum = 0;
	for (int i = 0; i < nLen; i++)
		nSum += pnArr[i];

	return nSum;
}