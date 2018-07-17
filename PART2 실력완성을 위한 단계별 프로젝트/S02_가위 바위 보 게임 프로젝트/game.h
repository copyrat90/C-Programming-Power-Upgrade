/* Name : game.h	ver 2.0
 * Content : 게임 관련 함수 선언
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#ifndef __GAME_H__
#define __GAME_H__

enum { SCISSORS = 1, ROCK, PAPER };

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);
void ShowRSP(int rsp);

#endif
// end of file