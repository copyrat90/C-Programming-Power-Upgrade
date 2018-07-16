/* Name : phoneFunc	ver 1.5
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

	for (int i = 0; i < numOfData; i++)
		if (!strcmp(phoneList[i]->phoneNum, pData->phoneNum))
		{
			free(pData);
			puts("이미 입력된 전화번호입니다.");
			getchar();
			return;
		}

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

	int dataCnt = 0;
	for (int i = 0; i < numOfData; i++)
		if (strcmp(searchName, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			dataCnt++;
		}

	if (dataCnt == 0)
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
	else
		puts("검색이 완료되었습니다.");
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

	int idxOfMatchingData[LIST_NUM];
	int matchCnt = 0;
	int i;
	for (i = 0; i < numOfData; i++)
		if (!strcmp(phoneList[i]->name, delName))
			idxOfMatchingData[matchCnt++] = i;

	int delIdx;
	if (matchCnt == 0)
	{
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}
	else if (matchCnt == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for (i = 0; i < matchCnt; i++)
		{
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		int choice;
		fputs("선택: ", stdout);
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		delIdx = idxOfMatchingData[choice - 1];
	}

	free(phoneList[delIdx]);
	for (i = delIdx; i < numOfData - 1; i++)
		phoneList[i] = phoneList[i + 1];
	numOfData--;

	puts("삭제가 완료되었습니다.");
	getchar();
	return;
}

/* 함수 : void StoreDataToFile(void);
 * 기능 : 종료 직전 파일에 데이터 저장
 * 반환 : void
 *
 */
void StoreDataToFile(void)
{
	FILE *fp = NULL;
	fopen_s(&fp, "phoneData.dat", "w");
	if (fp == NULL)
	{
		puts("'phoneData.dat' 파일을 열 수 없었습니다.\n파일 저장 실패!");
		return;
	}
	
	// 개수 입력
	fwrite(&numOfData, sizeof(int), 1, fp);

	for (int i = 0; i < numOfData; i++)
	{
		fprintf_s(fp, "%s\n%s\n", phoneList[i]->name, phoneList[i]->phoneNum);
		//fputs(phoneList[i]->name, fp);
		//fputc('\n', fp);
		//fputs(phoneList[i]->phoneNum, fp);
		//fputc('\n', fp);

		free(phoneList[i]);
	}

	fclose(fp);
}

/* 함수 : void LoadDataFromFile(void);
 * 기능 : 실행 직후 파일로부터 데이터 복원
 * 반환 : void
 *
 */
void LoadDataFromFile(void)
{
	FILE *fp = NULL;
	fopen_s(&fp, "phoneData.dat", "r");
	if (fp == NULL)
		return;

	fread_s(&numOfData, sizeof(numOfData), sizeof(int), 1, fp);

	int newlineIdx;
	for (int i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);
		// 구분자 '\n' 삭제
		newlineIdx = strlen(phoneList[i]->name) - 1;
		phoneList[i]->name[newlineIdx] = '\0'; 

		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);
		// 구분자 '\n' 삭제
		newlineIdx = strlen(phoneList[i]->phoneNum) - 1;
		phoneList[i]->phoneNum[newlineIdx] = '\0';
	}

	fclose(fp);
}
// end of file