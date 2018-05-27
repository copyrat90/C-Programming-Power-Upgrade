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
		fputs("나눗셈 위한 두 정수 입력 : ", stdout);
		scanf_s("%d %d", &nInputDividend, &nInputDivisor);

		nReturn = DivInt(nInputDividend, nInputDivisor, &nResultQuotient, &nResultRemainder);
		if (nReturn == ERR_DIVIDE_BY_ZERO)
			puts("0으로 나누는 오류발생! 숫자 재 입력\n");
		else
			break;
	}

	printf("몫 : %d, 나머지 : %d\n", nResultQuotient, nResultRemainder);

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