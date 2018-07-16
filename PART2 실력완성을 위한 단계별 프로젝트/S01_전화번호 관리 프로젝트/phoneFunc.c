/* Name : phoneFunc	ver 1.3
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

	for (int i = 0; i < numOfData; i++)
		if (strcmp(searchName, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			puts("�˻��� �Ϸ�Ǿ����ϴ�.");
			getchar();
			return;
		}

	puts("��ϵ��� ���� �̸��Դϴ�.");
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

	int i, j;
	for (i = 0; i < numOfData; i++)
		if (strcmp(delName, phoneList[i]->name) == 0)
		{
			free(phoneList[i]);

			for (j = i; j < numOfData - 1; j++)
				phoneList[j] = phoneList[j + 1];

			numOfData--;
			puts("������ �Ϸ�Ǿ����ϴ�.");
			getchar();
			return;
		}

	puts("��ϵ��� ���� �̸��Դϴ�.");
	getchar();
	return;
}

// end of file