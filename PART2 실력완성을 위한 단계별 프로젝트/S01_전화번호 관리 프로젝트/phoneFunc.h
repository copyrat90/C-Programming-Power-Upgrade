/* Name : phoneFunc.h	ver 1.4
 * Content : ��ȭ��ȣ ��Ʈ�� �Լ����� ����
 * Implementation : copyrat90
 *
 * Last modified 2018/07/16
 */

#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);

void SearchPhoneData(void);
void DeletePhoneData(void);
void ChangePhoneData(void);

void StoreDataToFile(void);
void LoadDataFromFile(void);
void StoreDataToFileInStruct(void);
void LoadDataFromFileInStruct(void);

#endif
// end of file