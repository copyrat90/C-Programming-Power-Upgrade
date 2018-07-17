/* Name : gameMoney.c	ver 1.0
 * Content : 게임머니 함수 정의
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

static int playerMoney;
static int comMoney;

static int bettingMoney;

/* 함	수 : void SetBettingMoney(int)
* 기	능 : 베팅액 설정
* 반	환 : void
*
*/
void SetBettingMoney(int money)
{
	if (money < 0)
		bettingMoney = 0;
	else
		bettingMoney = money;
}

/* 함	수 : void SetPlayerMoney(int)
 * 기	능 : 플레이어 머니 설정
 * 반	환 : void
 *
 */
void SetPlayerMoney(int money)
{
	if (money < 0)
		return;		// error!

	playerMoney = money;
}

/* 함	수 : int GetPlayerMoney(void)
 * 기	능 : 플레이어 머니 반환
 * 반	환 : int
 *
 */
int GetPlayerMoney(void)
{
	return playerMoney;
}

/* 함	수 : void SetComMoney(int)
* 기	능 : 컴퓨터 머니 설정
* 반	환 : void
*
*/
void SetComMoney(int money)
{
	if (money < 0)
		return;		// error!

	comMoney = money;
}

/* 함	수 : int GetComMoney(void)
 * 기	능 : 컴퓨터 머니 반환
 * 반	환 : int
 *
 */
int GetComMoney(void)
{
	return comMoney;
}

/* 함	수 : void PlayerEarnMoney(void)
 * 기	능 : 플레이어가 컴퓨터의 돈을 가져감
 * 반	환 : void
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

/* 함	수 : void PlayerLoseMoney(void)
 * 기	능 : 컴퓨터가 플레이어의 돈을 가져감
 * 반	환 : void
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