// 1���� �迭�� ���� ����ȯ�ϱ�
// ������ �迭�� ��Ҵ� �޸� �� �Ϸķ� �Ҵ�ǹǷ� 1���� �迭�� ���� ����ȯ�� ����ϸ� �Լ� �ϳ��ε� �����ϴ�.
// ������ �̴� �Ҹ�Ȯ�ϸ� ������ �߻� ���ɼ��� ���̹Ƿ� ���� ����� �ƴϴ�.

#include <stdio.h>

int ArrSum(int *, int);

int main(void)
{
	int arr3[2][2] = { 1, 3, 5, 7 };
	int arr4[2][3] = { 1, 2, 3, 4, 5, 6 };
	// arr4	1�� 2�� 3��
	// 1��	1	2	3
	// 2��	4	5	6

	// ������ �迭�� ������ �޸𸮿� ���� ������ �Ҵ�ǹǷ�
	// ���� ����ȯ���� 1���� �迭ó�� ���� �����ϴ�.
	int nSum3 = ArrSum((int*)arr3, 4);
	printf("1, 3, 5, 7�� �� : %d\n", nSum3);

	int nSum4 = ArrSum((int*)arr4, 6);
	printf("1, 2, 3, 4, 5, 6�� �� : %d\n", nSum4);

	return 0;
}

int ArrSum(int *pnArr, int nLen)
{
	int nSum = 0;
	for (int i = 0; i < nLen; i++)
		nSum += pnArr[i];

	return nSum;
}