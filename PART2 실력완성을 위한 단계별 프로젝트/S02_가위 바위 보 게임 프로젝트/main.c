/* Name : main.c	ver 2.0
 * Content : ���� main �Լ�
 * Implementation : copyrat90
 *
 * Last modified	2018/7/17
 */

#include "common.h"
#include "game.h"

int main(void)
{
	int com, you;
	puts("��! ������ �����մϴ�.\n");

	puts("�١١١١١� ���! �١١١١١�!!");
	com = ChoiceOfCom();
	you = ChoiceOfMe();
	putchar('\n');

	puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�!!");
	WhoIsWinner(com, you);

	fputs("��ǻ���� ����: ", stdout);
	ShowRSP(com);
	putchar('\n');

	fputs("����� ����: ", stdout);
	ShowRSP(you);

	putchar('\n');
	return 0;
}