/* Name : gameMoney.c	ver 1.1
 * Content : ���ӸӴ� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"

static int playerMoney;
static int comMoney;

static int bettingMoney;



/* ��	�� : void SetBettingMoney(int)
 * ��	�� : ���þ� ����
 * ��	ȯ : void
 *
 */
void SetBettingMoney(int money)
{
	if (money < 0)
		bettingMoney = 0;
	else
		bettingMoney = money;
}

/* ��	�� : void SetPlayerMoney(int)
 * ��	�� : �÷��̾� �Ӵ� ����
 * ��	ȯ : void
 *
 */
void SetPlayerMoney(int money)
{
	if (money < 0)
		return;		// error!

	playerMoney = money;
}

/* ��	�� : int GetPlayerMoney(void)
 * ��	�� : �÷��̾� �Ӵ� ��ȯ
 * ��	ȯ : int
 *
 */
int GetPlayerMoney(void)
{
	return playerMoney;
}

/* ��	�� : void SetComMoney(int)
* ��	�� : ��ǻ�� �Ӵ� ����
* ��	ȯ : void
*
*/
void SetComMoney(int money)
{
	if (money < 0)
		return;		// error!

	comMoney = money;
}

/* ��	�� : int GetComMoney(void)
 * ��	�� : ��ǻ�� �Ӵ� ��ȯ
 * ��	ȯ : int
 *
 */
int GetComMoney(void)
{
	return comMoney;
}

/* ��	�� : void PlayerEarnMoney(void)
 * ��	�� : �÷��̾ ��ǻ���� ���� ������
 * ��	ȯ : void
 *
 */
void PlayerEarnMoney(void)
{
	if (comMoney < bettingMoney)
	{
		playerMoney += comMoney;
		comMoney = 0;
	}
	else
	{
		playerMoney += bettingMoney;
		comMoney -= bettingMoney;
	}
}

/* ��	�� : void PlayerLoseMoney(void)
 * ��	�� : ��ǻ�Ͱ� �÷��̾��� ���� ������
 * ��	ȯ : void
 *
 */
void PlayerLoseMoney(void)
{
	if (playerMoney < bettingMoney)
	{
		comMoney += playerMoney;
		playerMoney = 0;
	}
	else
	{
		playerMoney -= bettingMoney;
		comMoney += bettingMoney;
	}
}

/* ��	�� : void UserInputPlayerMoney(void)
 * ��	�� : ����� �Է¹޾� �÷��̾� �Ӵ� ����
 * ��	ȯ : void
 *
 */
void UserInputPlayerMoney(void)
{
	int nMoney;

	while (1)
	{
		fputs("# ����� �Ӵϸ� �Է��ϼ���: ", stdout);
		scanf_s("%d", &nMoney);
		while (getchar() != '\n');

		if (nMoney <= 0)
			puts("0�� ������ �� �����ϴ�.\n");
		else
			break;
	}

	SetPlayerMoney(nMoney);
}

/* ��	�� : void UserInputBettingMoney(void)
 * ��	�� : ����� �Է¹޾� ���þ� ����
 * ��	ȯ : void
 *
 */
void UserInputBettingMoney(void)
{
	int nMoney;

	while (1)
	{
		puts("�� �ǵ� �����մϴ�! ��");
		fputs("�ǵ� �Է�: ", stdout);
		scanf_s("%d", &nMoney);
		while (getchar() != '\n');
		putchar('\n');

		if (nMoney > GetPlayerMoney())
		{
			puts("�����ϰ� �ִ� �ݾ� ������ �ż���!");
			printf("����� ���� ���� �Ӵ�: %d\n", GetPlayerMoney());
		}
		else if (nMoney > GetComMoney())
		{
			puts("��ǻ�� ���� �ݾ� �ʰ��Դϴ�!");
			printf("��ǻ���� ���� ���� �Ӵ�: %d\n", GetComMoney());
		}
		else if (nMoney <= 0)
			puts("0�� ������ �� �����ϴ�.\n");
		else
			break;
	}

	SetBettingMoney(nMoney);
}