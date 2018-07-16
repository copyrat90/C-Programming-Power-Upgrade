/* Name : phoneFunc	ver 1.5
 * Content : ��ȭ��ȣ ��Ʈ�� �Լ�
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

/* �Լ� : void InputPhoneData(void)
 * ��� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��ȯ : void
 *
 */
void InputPhoneData(void)
{
	phoneData *pData = NULL;

	if (numOfData >= LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("�̸� �Է� : ", stdout);
	gets_s(pData->name, sizeof(pData->name));

	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets_s(pData->phoneNum, sizeof(pData->phoneNum));

	for (int i = 0; i < numOfData; i++)
		if (!strcmp(phoneList[i]->phoneNum, pData->phoneNum))
		{
			free(pData);
			puts("�̹� �Էµ� ��ȭ��ȣ�Դϴ�.");
			getchar();
			return;
		}

	phoneList[numOfData] = pData;
	numOfData++;

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/* �Լ� : void ShowAllData(void)
 * ��� : ����� ������ ��ü ���
 * ��ȯ : void
 *
 */
void ShowAllData(void)
{
	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfoByPtr(phoneList[i]);

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/* �Լ� : void SearchPhoneData(void);
 * ��� : �̸��� �Է¹޾� �����͸� �˻� �� ���
 * ��ȯ : void
 *
 */
void SearchPhoneData(void)
{
	char searchName[NAME_LEN];

	if (numOfData == 0)
	{
		puts("����� ��ȭ��ȣ�� �����ϴ�!");
		getchar();
		return;
	}

	fputs("ã�� �̸���? ", stdout);
	gets_s(searchName, sizeof(searchName));

	int dataCnt = 0;
	for (int i = 0; i < numOfData; i++)
		if (strcmp(searchName, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			dataCnt++;
		}

	if (dataCnt == 0)
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
	else
		puts("�˻��� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}

/* �Լ� : void DeletePhoneData(void)
 * ��� : �̸��� �Է� �޾� �����͸� ����
 * ��ȯ : void
 *
 */
void DeletePhoneData(void)
{
	if (numOfData == 0)
	{
		puts("����� ��ȭ��ȣ�� �����ϴ�!");
		getchar();
		return;
	}

	char delName[NAME_LEN];
	fputs("ã�� �̸���? ", stdout);
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
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
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
		fputs("����: ", stdout);
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		delIdx = idxOfMatchingData[choice - 1];
	}

	free(phoneList[delIdx]);
	for (i = delIdx; i < numOfData - 1; i++)
		phoneList[i] = phoneList[i + 1];
	numOfData--;

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}

/* �Լ� : void StoreDataToFile(void);
 * ��� : ���� ���� ���Ͽ� ������ ����
 * ��ȯ : void
 *
 */
void StoreDataToFile(void)
{
	FILE *fp = NULL;
	fopen_s(&fp, "phoneData.dat", "w");
	if (fp == NULL)
	{
		puts("'phoneData.dat' ������ �� �� �������ϴ�.\n���� ���� ����!");
		return;
	}
	
	// ���� �Է�
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

/* �Լ� : void LoadDataFromFile(void);
 * ��� : ���� ���� ���Ϸκ��� ������ ����
 * ��ȯ : void
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
		// ������ '\n' ����
		newlineIdx = strlen(phoneList[i]->name) - 1;
		phoneList[i]->name[newlineIdx] = '\0'; 

		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);
		// ������ '\n' ����
		newlineIdx = strlen(phoneList[i]->phoneNum) - 1;
		phoneList[i]->phoneNum[newlineIdx] = '\0';
	}

	fclose(fp);
}
// end of file