/* Name : main.c	ver 2.3
 * Content : ���� main �Լ�
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

int main(void)
{
	int com, you, playerMoney, comMoney;

	puts("��! ������ �����մϴ�.\n");

	SetComMoney(1000);

	UserInputPlayerMoney();
	printf("����� ���� �Ӵ�: %d\n", GetPlayerMoney());
	printf("��ǻ�� ���� �Ӵ�: %d\n\n", GetComMoney());

	while (1)
	{
		UserInputBettingMoney();

		puts("�١١١١١� ���! �١١١١١�!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		putchar('\n');

		if (you == QUIT)
			break;

		puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�!!");
		WhoIsWinner(com, you);

		fputs("��ǻ���� ����: ", stdout);
		ShowRSP(com);
		putchar('\n');

		fputs("����� ����: ", stdout);
		ShowRSP(you);
		putchar('\n');

		printf("�·�: %d %%\n", GetIntWinningRate());
		printf("���̸� �Ӵ�: %d\n", playerMoney = GetPlayerMoney());
		printf("��ǻ�� �Ӵ�: %d\n\n", comMoney = GetComMoney());

		if (playerMoney <= 0 || comMoney <= 0)
			break;
	}

	puts("�ޡޡޡޡޡ� ���� ��� �ޡޡޡޡޡ�");
	printf("�·�: %d %%\n", GetIntWinningRate());
	puts("�̿��� �ּż� ������~");

	return 0;
}