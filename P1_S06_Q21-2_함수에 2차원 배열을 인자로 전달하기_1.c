#include <stdio.h>


int Arr3Sum(int(*)[2], int);
int Arr4Sum(int(*)[3], int);

int main(void)
{
	int arr3[2][2] = { 1, 3, 5, 7 };
	int arr4[2][3] = { 1, 2, 3, 4, 5, 6 };
	// arr4	1�� 2�� 3��
	// 1��	1	2	3
	// 2��	4	5	6

	int nSum3 = Arr3Sum(arr3, 2);
	printf("1, 3, 5, 7�� �� : %d\n", nSum3);

	int nSum4 = Arr4Sum(arr4, 2);
	printf("1, 2, 3, 4, 5, 6�� �� : %d\n", nSum4);

	return 0;
}

// 2�� (���� ���̰� 2 == ���� ������ 2)
int Arr3Sum(int(*parr3)[2], int nRow)
{
	int i, j;
	int nSum = 0;
	
	for (i = 0; i < nRow; i++)
		for (j = 0; j < 2; j++)
			nSum += parr3[i][j];

	return nSum;
}

// 3�� (���� ���̰� 3 == ���� ������ 3)
int Arr4Sum(int(*parr4)[3], int nRow)
{
	int i, j;
	int nSum = 0;

	for (i = 0; i < nRow; i++)
		for (j = 0; j < 3; j++)
			nSum += parr4[i][j];

	return nSum;
}