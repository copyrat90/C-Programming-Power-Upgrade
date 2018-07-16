/* Name : screenOut.c	ver 1.3
 * Content : 콘솔 출력을 위한 함수 정의
 * Implementation : copyrat90
 *
 * Last modified 2018/07/16
 */

#include "common.h"
#include "phoneData.h"

/* 함수 : void ShowMenu(void)
 * 기능 : 선택을 위한 메뉴 출력
 * 반환 : void
 *
 */
void ShowMenu(void)
{
	system("cls");		// stdlib.h
	printf("────────── 메  뉴 ──────────\n");
	printf(" 1. 전화번호 입력\n");
	printf(" 2. 전체 정보 출력\n");
	printf(" 3. 전화번호 검색\n");
	printf(" 4. 전화번호 삭제\n");
	printf(" 5. 전화번화 변경\n");
	printf(" 6. 종료\n");
	printf("────────────────────────────\n");
	printf("선택>> ");
}

/* 함수 : void ShowPhoneInfo(phoneData phone)
 * 기능 : 이름과 전화번호 정보 출력
 * 반환 : void
 *
 */
void ShowPhoneInfo(phoneData phone)
{
	printf("┌────────────────────────────\n");
	printf("│  ▶ 이름 : %s \n", phone.name);
	printf("│  ▶ 전화번호 : %s \n", phone.phoneNum);
	printf("└────────────────────────────\n\n");
}

/* 함수 : void ShoePhoneInfoByPtr(const phoneData *pPhone)
 * 기능 : 이름과 전화번호 정보 출력(포인터 버전)
 * 반환 : void
 *
 */
void ShowPhoneInfoByPtr(const phoneData *pPhone)
{
	printf("┌────────────────────────────\n");
	printf("│  ▶ 이름 : %s \n", pPhone->name);
	printf("│  ▶ 전화번호 : %s \n", pPhone->phoneNum);
	printf("└────────────────────────────\n\n");
}

// end of file