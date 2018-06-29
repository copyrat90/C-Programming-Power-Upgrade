/* Name : phoneFunc	ver 1.1
 * Content : ��ȭ��ȣ ��Ʈ�� �Լ�
 * Implementation : copyrat90
 * 
 * Last modified 2018/06/29
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM	100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

/* �Լ� : void InputPhoneData(void)
 * ��� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��ȯ : void
 *
 */
void InputPhoneData(void)
{
	phoneData phoneBuff;

	if (numOfData >= LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	fputs("�̸� �Է� : ", stdout);
	gets_s(phoneBuff.name, sizeof(phoneBuff.name));

	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets_s(phoneBuff.phoneNum, sizeof(phoneBuff.phoneNum));

	phoneList[numOfData] = phoneBuff;
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
		ShowPhoneInfo(phoneList[i]);

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}
// end of file