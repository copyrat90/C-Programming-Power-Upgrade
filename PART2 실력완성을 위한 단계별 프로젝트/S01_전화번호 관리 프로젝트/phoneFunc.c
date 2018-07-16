/* Name : phoneFunc	ver 1.3
 * Content : 전화번호 컨트롤 함수
 * Implementation : copyrat90
 * 
 * Last modified 2018/07/16
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM	100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

/* 함수 : void InputPhoneData(void)
 * 기능 : 전화번호 관련 데이터 입력 받아서 저장
 * 반환 : void
 *
 */
void InputPhoneData(void)
{
	phoneData *pData = NULL;

	if (numOfData >= LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}

	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("이름 입력 : ", stdout);
	gets_s(pData->name, sizeof(pData->name));

	fputs("전화번호 입력 : ", stdout);
	gets_s(pData->phoneNum, sizeof(pData->phoneNum));

	phoneList[numOfData] = pData;
	numOfData++;

	puts("입력이 완료되었습니다.");
	getchar();
}

/* 함수 : void ShowAllData(void)
 * 기능 : 저장된 데이터 전체 출력
 * 반환 : void
 *
 */
void ShowAllData(void)
{
	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfoByPtr(phoneList[i]);

	puts("출력이 완료되었습니다.");
	getchar();
}

/* 함수 : void SearchPhoneData(void);
 * 기능 : 이름을 입력받아 데이터를 검색 후 출력
 * 반환 : void
 *
 */
void SearchPhoneData(void)
{
	char searchName[NAME_LEN];

	if (numOfData == 0)
	{
		puts("저장된 전화번호가 없습니다!");
		getchar();
		return;
	}

	fputs("찾는 이름은? ", stdout);
	gets_s(searchName, sizeof(searchName));

	for (int i = 0; i < numOfData; i++)
		if (strcmp(searchName, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			puts("검색이 완료되었습니다.");
			getchar();
			return;
		}

	puts("등록되지 않은 이름입니다.");
	getchar();
	return;
}

/* 함수 : void DeletePhoneData(void)
 * 기능 : 이름을 입력 받아 데이터를 삭제
 * 반환 : void
 *
 */
void DeletePhoneData(void)
{
	if (numOfData == 0)
	{
		puts("저장된 전화번호가 없습니다!");
		getchar();
		return;
	}

	char delName[NAME_LEN];
	fputs("찾는 이름은? ", stdout);
	gets_s(delName, sizeof(delName));

	int i, j;
	for (i = 0; i < numOfData; i++)
		if (strcmp(delName, phoneList[i]->name) == 0)
		{
			free(phoneList[i]);

			for (j = i; j < numOfData - 1; j++)
				phoneList[j] = phoneList[j + 1];

			numOfData--;
			puts("삭제가 완료되었습니다.");
			getchar();
			return;
		}

	puts("등록되지 않은 이름입니다.");
	getchar();
	return;
}

// end of file