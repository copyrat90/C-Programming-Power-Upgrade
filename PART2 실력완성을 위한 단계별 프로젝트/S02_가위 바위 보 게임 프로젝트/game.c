/* Name : game.c	ver 2.0
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
 * ��	ȯ : 1~3 ������ ���� ��ȯ
 *
 */
int ChoiceOfCom(void)
{
	srand((unsigned int)time(NULL));
	return rand() % 3 + 1;
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
		printf("����(%d) ����(%d) ��(%d) ����? ", SCISSORS, ROCK, PAPER);
		scanf_s("%d", &nChoice);
		while (getchar() != '\n');

		if (nChoice == SCISSORS || nChoice == ROCK || nChoice == PAPER)
			break;

		printf("%d, %d, %d �� �Է� �����մϴ�.\n\n", SCISSORS, ROCK, PAPER);
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
	int outcome = you - com;
	switch (outcome)
	{
	case 0:
		puts("�����ϴ�.");
		break;

	case 1: case -2:
		puts("����� �����Դϴ�!");
		break;

	default:
		puts("��ǻ�Ͱ� �����̱���!");
		break;
	}
}

/* ��	�� : void ShowRSP(int rsp) 
 * ��	�� : ����� ���� ���ڿ�("����", "����", "��") ���
 * ��	ȯ : void
 *
 */
void ShowRSP(int rsp)
{
	switch (rsp)
	{
	case SCISSORS:
		fputs("����", stdout);
		break;

	case ROCK:
		fputs("����", stdout);
		break;

	case PAPER:
		fputs("��", stdout);
		break;
	}
}

// end of file