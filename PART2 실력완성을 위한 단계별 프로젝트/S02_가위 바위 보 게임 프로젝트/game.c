/* Name : game.c	ver 2.0
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
 * 반	환 : 1~3 범위의 값을 반환
 *
 */
int ChoiceOfCom(void)
{
	srand((unsigned int)time(NULL));
	return rand() % 3 + 1;
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
		printf("가위(%d) 바위(%d) 보(%d) 선택? ", SCISSORS, ROCK, PAPER);
		scanf_s("%d", &nChoice);
		while (getchar() != '\n');

		if (nChoice == SCISSORS || nChoice == ROCK || nChoice == PAPER)
			break;

		printf("%d, %d, %d 만 입력 가능합니다.\n\n", SCISSORS, ROCK, PAPER);
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
	int outcome = you - com;
	switch (outcome)
	{
	case 0:
		puts("비겼습니다.");
		break;

	case 1: case -2:
		puts("당신이 승자입니다!");
		break;

	default:
		puts("컴퓨터가 승자이군요!");
		break;
	}
}

/* 함	수 : void ShowRSP(int rsp) 
 * 기	능 : 상수에 따른 문자열("가위", "바위", "보") 출력
 * 반	환 : void
 *
 */
void ShowRSP(int rsp)
{
	switch (rsp)
	{
	case SCISSORS:
		fputs("가위", stdout);
		break;

	case ROCK:
		fputs("바위", stdout);
		break;

	case PAPER:
		fputs("보", stdout);
		break;
	}
}

// end of file