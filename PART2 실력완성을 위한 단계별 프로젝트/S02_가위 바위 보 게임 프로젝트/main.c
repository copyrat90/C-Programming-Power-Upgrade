/* Name : main.c	ver 1.0 
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

	printf("�� ��ǻ���� ������ %d\n", com);

	if (you == EVEN)
		puts("�� ����� ������ ¦��.");
	else
		puts("�� ����� ������ Ȧ��.");

	putchar('\n');
	return 0;
}