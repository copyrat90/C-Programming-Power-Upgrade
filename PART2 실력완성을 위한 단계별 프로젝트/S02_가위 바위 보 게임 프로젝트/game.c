/* Name : game.c	ver 1.1
 * Content : 게임 관련 함수 정의
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include <time.h>
#include "common.h"
#include "game.h"

/* 함	수 : int ChoiceOfCom(void)
 * 기	능 : 무작위 값을 반환
 * 반	환 : 0~99 범위의 값을 반환
 *
 */
int ChoiceOfCom(void)
{
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

/* 함	수 : int ChoiceOfMe(void)
 * 기	능 : 사용자의 선택을 입력 받음
 * 반	환 : 사용자 입력
 *
 */
int ChoiceOfMe(void)
{
	int nChoice;
	while (1)
	{
		printf("홀수이면 %d, 짝수이면 %d를 입력 : ", ODD, EVEN);
		scanf_s("%d", &nChoice);
		while (getchar() != '\n');

		if (nChoice == ODD || nChoice == EVEN)
			break;

		puts("1 또는 2 만 입력 가능합니다.");
	}

	return nChoice;
}

/* 함	수 : void WhoIsWinner(int com, int you)
 * 기	능 : 승자를 가림
 * 반	환 : void
 *
 */
void WhoIsWinner(int com, int you)
{
	if (com % 2 == you % 2)
		puts("당신이 승자입니다!");
	else
		puts("컴퓨터가 승자이군요!");
}

// end of file