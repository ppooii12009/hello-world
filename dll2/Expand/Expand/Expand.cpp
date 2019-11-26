﻿// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include "windows.h"

typedef void (*PINIT)(const unsigned long long a, const unsigned long long b);
typedef bool (*PNEXT)();
typedef int (*PINDEX)();
typedef unsigned long long (*PCURRENT)();
int main()
{
	HMODULE hDLL = LoadLibrary(L"../../MathLibrary/Debug/MathLibrary.dll");

	if (hDLL == NULL)
	{
		std::cout << "获取动态链接库失败!" << std::endl;
		return 0;
	}

	PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
	PNEXT fibonacci_next = (PNEXT)GetProcAddress(hDLL, "fibonacci_next");
	PINDEX fibonacci_index = (PINDEX)GetProcAddress(hDLL, "fibonacci_index");
	PCURRENT fibonacci_current = (PCURRENT)GetProcAddress(hDLL, "fibonacci_current");
	// Initialize a Fibonacci relation sequence.
	if(fibonacci_init != NULL)
	{
		fibonacci_init(20, 10);
	}
	
	
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;
	FreeLibrary(hDLL);
}