/* Name : gameMoney.c	ver 1.1
 * Content : 게임머니 함수 정의
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"

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

/* 함	수 : void UserInputPlayerMoney(void)
 * 기	능 : 사용자 입력받아 플레이어 머니 설정
 * 반	환 : void
 *
 */
void UserInputPlayerMoney(void)
{
	int nMoney;

	while (1)
	{
		fputs("# 당신의 머니를 입력하세요: ", stdout);
		scanf_s("%d", &nMoney);
		while (getchar() != '\n');

		if (nMoney <= 0)
			puts("0원 이하일 수 없습니다.\n");
		else
			break;
	}

	SetPlayerMoney(nMoney);
}

/* 함	수 : void UserInputBettingMoney(void)
 * 기	능 : 사용자 입력받아 베팅액 설정
 * 반	환 : void
 *
 */
void UserInputBettingMoney(void)
{
	int nMoney;

	while (1)
	{
		puts("∮ 판돈 설정합니다! ∮");
		fputs("판돈 입력: ", stdout);
		scanf_s("%d", &nMoney);
		while (getchar() != '\n');
		putchar('\n');

		if (nMoney > GetPlayerMoney())
		{
			puts("소유하고 있는 금액 내에서 거세요!");
			printf("당신의 현재 게임 머니: %d\n", GetPlayerMoney());
		}
		else if (nMoney > GetComMoney())
		{
			puts("컴퓨터 소유 금액 초과입니다!");
			printf("컴퓨터의 현재 게임 머니: %d\n", GetComMoney());
		}
		else if (nMoney <= 0)
			puts("0원 이하일 수 없습니다.\n");
		else
			break;
	}

	SetBettingMoney(nMoney);
}