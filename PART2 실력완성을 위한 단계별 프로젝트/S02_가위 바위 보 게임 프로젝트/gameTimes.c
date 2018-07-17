/* Name : gameTimes.c	ver 1.0
* Content : �·� ��� �Լ� ����
* Implementation : copyrat90
*
* Last modified	2018/7/17
*/

// static �������� �ٸ� ���Ͽ��� ���� �Ұ�
static int playCnt = 0, winCnt = 0;

/* ��	�� : void IncreasePlayCnt(void)
 * ��	�� : �÷��� Ƚ�� ����
 * ��	ȯ : void
 *
 */
void IncreasePlayCnt(void)
{
	playCnt++;
}

/* ��	�� : int GetPlayCnt(void)
 * ��	�� : �÷��� Ƚ�� ��ȯ
 * ��	ȯ : int
 *
 */
int GetPlayCnt(void)
{
	return playCnt;
}

/* ��	�� : void IncreaseWinCnt(void)
* ��	�� : �¸� Ƚ�� ����
* ��	ȯ : void
*
*/
void IncreaseWinCnt(void)
{
	winCnt++;
}

/* ��	�� : int GetWinCnt(void)
* ��	�� : �¸� Ƚ�� ��ȯ
* ��	ȯ : int
*
*/
int GetWinCnt(void)
{
	return winCnt;
}

/* ��	�� : int GetIntWinningRate(void)
* ��	�� : �·��� 0~100 ���� ������ ��ȯ
* ��	ȯ : 0~100 ���� ����
*
*/
int GetIntWinningRate(void)
{
	if (playCnt == 0)
		return 0;

	return (int)((double)GetWinCnt() / GetPlayCnt() * 100);
}

// end of file