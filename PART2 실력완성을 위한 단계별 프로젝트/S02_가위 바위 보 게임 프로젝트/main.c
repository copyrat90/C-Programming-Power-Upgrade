/* Name : main.c	ver 2.0
 * Content : 게임 main 함수
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"
#include "game.h"

int main(void)
{
	int com, you;
	puts("자! 게임을 시작합니다.\n");

	puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆!!");
	com = ChoiceOfCom();
	you = ChoiceOfMe();
	putchar('\n');

	puts("★★★★★★ 결과! ★★★★★★!!");
	WhoIsWinner(com, you);

	fputs("컴퓨터의 선택: ", stdout);
	ShowRSP(com);
	putchar('\n');

	fputs("당신의 선택: ", stdout);
	ShowRSP(you);

	putchar('\n');
	return 0;
}