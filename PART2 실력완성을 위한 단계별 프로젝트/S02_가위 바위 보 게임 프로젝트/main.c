/* Name : main.c	ver 2.1
 * Content : 게임 main 함수
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"

int main(void)
{
	int com, you;
	puts("자! 게임을 시작합니다.\n");

	while (1)
	{
		puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		putchar('\n');

		if (you == QUIT)
			break;

		puts("★★★★★★ 결과! ★★★★★★!!");
		WhoIsWinner(com, you);

		fputs("컴퓨터의 선택: ", stdout);
		ShowRSP(com);
		putchar('\n');

		fputs("당신의 선택: ", stdout);
		ShowRSP(you);
		putchar('\n');

		printf("승률: %d %%\n\n", GetIntWinningRate());
	}

	puts("◇◇◇◇◇◇ 최종 결과 ◇◇◇◇◇◇");
	printf("승률: %d %%\n", GetIntWinningRate());
	puts("이용해 주셔서 고마워요~");

	return 0;
}