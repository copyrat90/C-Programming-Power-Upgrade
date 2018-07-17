/* Name : game.c	ver 1.1
 * Content : ���� ���� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include <time.h>
#include "common.h"
#include "game.h"

/* ��	�� : int ChoiceOfCom(void)
 * ��	�� : ������ ���� ��ȯ
 * ��	ȯ : 0~99 ������ ���� ��ȯ
 *
 */
int ChoiceOfCom(void)
{
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

/* ��	�� : int ChoiceOfMe(void)
 * ��	�� : ������� ������ �Է� ����
 * ��	ȯ : ����� �Է�
 *
 */
int ChoiceOfMe(void)
{
	int nChoice;
	while (1)
	{
		printf("Ȧ���̸� %d, ¦���̸� %d�� �Է� : ", ODD, EVEN);
		scanf_s("%d", &nChoice);
		while (getchar() != '\n');

		if (nChoice == ODD || nChoice == EVEN)
			break;

		puts("1 �Ǵ� 2 �� �Է� �����մϴ�.");
	}

	return nChoice;
}

/* ��	�� : void WhoIsWinner(int com, int you)
 * ��	�� : ���ڸ� ����
 * ��	ȯ : void
 *
 */
void WhoIsWinner(int com, int you)
{
	if (com % 2 == you % 2)
		puts("����� �����Դϴ�!");
	else
		puts("��ǻ�Ͱ� �����̱���!");
}

// end of file