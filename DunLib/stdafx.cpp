// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// DunLib.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������

bool SetConsoleColor(WORD wAttributes)
{
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (hConsole == INVALID_HANDLE_VALUE)
			return FALSE;

		return SetConsoleTextAttribute(hConsole, wAttributes);
	}
}
