/* Name : main.c	ver 2.1
 * Content : ���� main �Լ�
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
	puts("��! ������ �����մϴ�.\n");

	while (1)
	{
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

		printf("�·�: %d %%\n\n", GetIntWinningRate());
	}

	puts("�ޡޡޡޡޡ� ���� ��� �ޡޡޡޡޡ�");
	printf("�·�: %d %%\n", GetIntWinningRate());
	puts("�̿��� �ּż� ������~");

	return 0;
}