/* Name : main.c	ver 1.2
 * Content : main �Լ�
 * Implementation : copyrat90
 *
 * Last modified 2018/07/16
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, QUIT };

/* �Լ� : int main(void)
 * ��� : ����� ���� ó��
 * ��ȯ : ���� ���� �� 0
 *
 */
int main(void)
{
	int inputMenu = 0;
	LoadDataFromFile();

	while (1)
	{
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
		scanf_s("%d", &inputMenu);
		while (getc(stdin) != '\n');

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;

		case SHOWALL:
			ShowAllData();
			break;

		case SEARCH:
			SearchPhoneData();
			break;

		case DELETE:
			DeletePhoneData();
			break;
		}

		if (inputMenu == QUIT)
		{
			StoreDataToFile();
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}

// end of file