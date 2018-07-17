/* Name : gameTimes.c	ver 1.0
* Content : 승률 출력 함수 정의
* Implementation : copyrat90
*
* Last modified	2018/7/17
*/

// static 선언으로 다른 파일에서 접근 불가
static int playCnt = 0, winCnt = 0;

/* 함	수 : void IncreasePlayCnt(void)
 * 기	능 : 플레이 횟수 증가
 * 반	환 : void
 *
 */
void IncreasePlayCnt(void)
{
	playCnt++;
}

/* 함	수 : int GetPlayCnt(void)
 * 기	능 : 플레이 횟수 반환
 * 반	환 : int
 *
 */
int GetPlayCnt(void)
{
	return playCnt;
}

/* 함	수 : void IncreaseWinCnt(void)
* 기	능 : 승리 횟수 증가
* 반	환 : void
*
*/
void IncreaseWinCnt(void)
{
	winCnt++;
}

/* 함	수 : int GetWinCnt(void)
* 기	능 : 승리 횟수 반환
* 반	환 : int
*
*/
int GetWinCnt(void)
{
	return winCnt;
}

/* 함	수 : int GetIntWinningRate(void)
* 기	능 : 승률을 0~100 사이 정수로 반환
* 반	환 : 0~100 사이 정수
*
*/
int GetIntWinningRate(void)
{
	if (playCnt == 0)
		return 0;

	return (int)((double)GetWinCnt() / GetPlayCnt() * 100);
}

// end of file