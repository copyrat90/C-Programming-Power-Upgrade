#include <stdio.h>


int ArrSum(int *, int);

int main(void)
{
	int arr3[2][2] = { 1, 3, 5, 7 };
	int arr4[2][3] = { 1, 2, 3, 4, 5, 6 };
	// arr4	1열 2열 3열
	// 1행	1	2	3
	// 2행	4	5	6

	// 다차원 배열도 어차피 메모리에 선형 구조로 할당되므로
	// 강제 형변환으로 1차원 배열처럼 접근 가능하다.
	int nSum3 = ArrSum((int*)arr3, 4);
	printf("1, 3, 5, 7의 합 : %d\n", nSum3);

	int nSum4 = ArrSum((int*)arr4, 6);
	printf("1, 2, 3, 4, 5, 6의 합 : %d\n", nSum4);

	return 0;
}

int ArrSum(int *pnArr, int nLen)
{
	int nSum = 0;
	for (int i = 0; i < nLen; i++)
		nSum += pnArr[i];

	return nSum;
}