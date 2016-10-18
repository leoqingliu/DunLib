// stdafx.cpp : 只包括标准包含文件的源文件
// DunLib.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

bool SetConsoleColor(WORD wAttributes)
{
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (hConsole == INVALID_HANDLE_VALUE)
			return FALSE;

		return SetConsoleTextAttribute(hConsole, wAttributes);
	}
}
