#include <stdio.h>
#define ERR_DIVIDE_BY_ZERO -256

int DivInt(int, int, int *, int *);

int main(void)
{
	int nInputDividend = 0;
	int nInputDivisor = 0;
	int nResultQuotient = 0;
	int nResultRemainder = 0;
	int nReturn = 0;
	
	while (1)
	{
		fputs("������ ���� �� ���� �Է� : ", stdout);
		scanf_s("%d %d", &nInputDividend, &nInputDivisor);

		nReturn = DivInt(nInputDividend, nInputDivisor, &nResultQuotient, &nResultRemainder);
		if (nReturn == ERR_DIVIDE_BY_ZERO)
			puts("0���� ������ �����߻�! ���� �� �Է�\n");
		else
			break;
	}

	printf("�� : %d, ������ : %d\n", nResultQuotient, nResultRemainder);

	return 0;
}

int DivInt(int nDividend, int nDivisor, int *nQuotient, int *nRemainder)
{
	if (nDivisor == 0)
		return ERR_DIVIDE_BY_ZERO;
	
	*nQuotient = nDividend / nDivisor;
	*nRemainder = nDividend % nDivisor;

	return 1;
}