/* Name : game.h	ver 1.0
 * Content : ���� ���� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#ifndef __GAME_H__
#define __GAME_H__

enum { ODD = 1, EVEN };

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);

#endif
// end of file