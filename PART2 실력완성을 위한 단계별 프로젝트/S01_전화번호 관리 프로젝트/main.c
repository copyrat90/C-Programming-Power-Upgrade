/* Name : main.c	ver 1.4
 * Content : main 함수
 * Implementation : copyrat90
 *
 * Last modified 2018/07/16
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

/* 함수 : int main(void)
 * 기능 : 사용자 선택 처리
 * 반환 : 정상 종료 시 0
 *
 */
int main(void)
{
	int inputMenu = 0;
	LoadDataFromFileInStruct();

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

		case SEARCH:
			SearchPhoneData();
			break;

		case DELETE:
			DeletePhoneData();
			break;

		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT)
		{
			StoreDataToFileInStruct();
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}

// end of file