/* Name : gameMoney.c	ver 1.0
 * Content : ���ӸӴ� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

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