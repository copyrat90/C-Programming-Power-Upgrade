/* Name : screenOut.h	ver 1.1
 * Content : �ܼ� ����� ���� �Լ� ����
 * Implementation : copyrat90
 *
 * Last modified 2018/07/16
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(const phoneData *pPhone);

#endif
// end of file