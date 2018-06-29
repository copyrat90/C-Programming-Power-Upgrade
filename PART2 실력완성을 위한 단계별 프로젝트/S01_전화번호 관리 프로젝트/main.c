/* Name : main.c	ver 1.0
 * Content : main 함수
 * Implementation : copyrat90
 *
 * Last modified : 2018/06/29
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, QUIT };

/* 함수 : int main(void)
 * 기능 : 사용자 선택 처리
 * 반환 : 정상 종료 시 0
 *
 */
int main(void)
{
	int inputMenu = 0;

	while (1)
	{
		ShowMenu();
		fputs("선택하세요 : ", stdout);
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
		}

		if (inputMenu == QUIT)
		{
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}

// end of file