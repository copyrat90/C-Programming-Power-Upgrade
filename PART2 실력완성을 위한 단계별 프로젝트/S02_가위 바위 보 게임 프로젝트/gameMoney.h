/* Name : gameMoney.h	ver 1.1
 * Content : 게임머니 함수 선언
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#ifndef __GAMEMONEY_H__
#define __GAMEMONEY_H__

void SetBettingMoney(int money);

int GetPlayerMoney(void);
void SetPlayerMoney(int money);

int GetComMoney(void);
void SetComMoney(int money);

void PlayerEarnMoney(void);
void PlayerLoseMoney(void);

void UserInputPlayerMoney(void);
void UserInputBettingMoney(void);

#endif