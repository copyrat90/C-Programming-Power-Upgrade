/* Name : game.c	ver 2.1
 * Content : ���� ���� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"

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
		printf("����(%d) ����(%d) ��(%d) ����(%d) ����? ", SCISSORS, ROCK, PAPER, QUIT);
		scanf_s("%d", &nChoice);
		while (getchar() != '\n');

		if (1 <= nChoice && nChoice <= 4)
			break;

		puts("1~4 ���� ���ڸ� �Է� �����մϴ�.\n");
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
	IncreasePlayCnt();

	switch (outcome)
	{
	case 0:
		puts("�����ϴ�.");
		return;

	case 1: case -2:
		puts("����� �����Դϴ�!");
		IncreaseWinCnt();
		return;

	default:
		puts("��ǻ�Ͱ� �����̱���!");
		return;
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