#pragma once
#include <cstdio>
#include <iostream>

class TextFile
{
	char* fileName;//имя файла
	FILE* file;//поток доступа к файлу
	int stringsAmount;//кол-во строк в файле
	
	class Str {
	public:
		char* letters;//набор символов
	};

	Str* strings;//набор строк заданной длины
	int strSize;//длина набора строк
	

	void inputStrings();//добавление строк в файл
	void getStrings();//составление набора строк заданной длины из строк файла
	
	
public:
	TextFile(int i);//создание файла
	void writeStringsFromFile(const TextFile& first);//запись набора строк из одного файла в другой
	void deleteStrings();//удаление набора строк заданной длины из файла
	~TextFile();//очищение памяти
};

