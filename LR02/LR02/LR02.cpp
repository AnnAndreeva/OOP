#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include "TextFile.h"

using namespace std;

int main()
{
	setlocale(0, "");//Разрешить кириллицу
	puts("Лабораторная работа №2. Вариант №4.");
	puts("Выполнила: Андреева А.А., группа 6213-020302D");

	TextFile firstFile(1);
	TextFile secondFile(2);
	secondFile.writeStringsFromFile(firstFile);//запись строк из первого файла во второй
	firstFile.deleteStrings();//удаление строк в первом файле
	system("pause");//Задержать консоль на экране при завершении программы
	return 0;
}

