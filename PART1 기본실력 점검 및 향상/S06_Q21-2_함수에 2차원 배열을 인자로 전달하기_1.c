// 일반적인 접근법
// int nArr[2][3] 와 같은 배열이 있으면 이는 2행 3열짜리 배열이다.
// 이 배열은 길이가 2이고 요소의 자료형은 int[3] 이다.
// 포인터는 가리키는 요소의 자료형을 따르므로 이 배열을 포인터에 담을 때는 int(*pnArr)[3] 에다 담아야 한다.
// 다시 말해 열의 개수(= 행의 길이)가 달라지면 요소의 자료형이 달라지므로 함수를 따로 정의해줘야 한다.

#include <stdio.h>


int Arr3Sum(int(*)[2], int);
int Arr4Sum(int(*)[3], int);

int main(void)
{
	int arr3[2][2] = { 1, 3, 5, 7 };
	int arr4[2][3] = { 1, 2, 3, 4, 5, 6 };
	// arr4	1열 2열 3열
	// 1행	1	2	3
	// 2행	4	5	6

	int nSum3 = Arr3Sum(arr3, 2);
	printf("1, 3, 5, 7의 합 : %d\n", nSum3);

	int nSum4 = Arr4Sum(arr4, 2);
	printf("1, 2, 3, 4, 5, 6의 합 : %d\n", nSum4);

	return 0;
}

// 2열 (행의 길이가 2 == 열의 개수가 2)
int Arr3Sum(int(*parr3)[2], int nRow)
{
	int i, j;
	int nSum = 0;
	
	for (i = 0; i < nRow; i++)
		for (j = 0; j < 2; j++)
			nSum += parr3[i][j];

	return nSum;
}

// 3열 (행의 길이가 3 == 열의 개수가 3)
int Arr4Sum(int(*parr4)[3], int nRow)
{
	int i, j;
	int nSum = 0;

	for (i = 0; i < nRow; i++)
		for (j = 0; j < 3; j++)
			nSum += parr4[i][j];

	return nSum;
}