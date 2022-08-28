#define _CRT_SECURE_NO_WARNINGS
#include "TextFile.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
int strLength;//длина, задающаяся пользователем

TextFile::TextFile(int i)//создание файла
{
	puts("Введите имя файла: ");
	char* name = (char*)malloc(255 * sizeof(char));//выделение памяти для имени 
	int nameSize = 0;
	for (; (nameSize < 255) && ((name[nameSize++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	name[nameSize - 1] = '\0';
	strcat(name, ".txt");
	nameSize += 4;
	name = (char*)realloc(name, (nameSize) * sizeof(char));//перераспределение памяти, выделенной  для имени
	fileName = (char*)realloc(name, (nameSize) * sizeof(char));//выделение памяти для имени файла
	memcpy(fileName, name, nameSize);
	if (i == 1) {
		inputStrings();
	}

}

void TextFile::inputStrings()//добавление строк в файл
{
	file = fopen(fileName, "w"); //открыть файл для записи; файл создается, если он не существует;
	if (file == NULL) {
		perror("Ошибка при открытии  файла");
	}
	else {
		puts("Введите количество строк в файле: ");
		//считывание количества строк
		char* amount = (char*)malloc(255 * sizeof(char));
		int size = 0;
		for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//считывание введенных символов
		{
		}
		amount = (char*)realloc(amount, (size) * sizeof(char));//перераспределение памяти
		amount[size - 1] = '\0';
		stringsAmount = strtol(amount, nullptr, 10);//преобразование в int

		char* str = (char*)malloc(255 * sizeof(char));
		puts("Введите cтроки:");
		for (int i = 0; i < stringsAmount; i++)
		{
			fgets(str, 255, stdin);//считывание строки с консоли
			fprintf(file, str);	 //запись строки в файл
		}
		fclose(file);//закрываем поток
		getStrings();//составление набора строк нужной длины из строк файла
	}
}

void TextFile::getStrings() //составление набора строк заданной длины из строк файла
{
	puts("Введите размер строк, которые вы хотите выделить в файле: ");
	//считывание длины строк
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//удаление лишней памяти
	amount[size - 1] = '\0';
	strLength = strtol(amount, nullptr, 10);//преобразование в int

	file = fopen(fileName, "r"); //открыть файл для чтения
	char* str = (char*)malloc(255 * sizeof(char));
	str[0] = '\0';
	str[255] = '\0';
	strSize = 0;
	strings = (Str*)malloc((stringsAmount) * sizeof(Str));//выделение памяти для списка строк
	char c;
	//составление списка строк больше заданной длины
	for (int i = 0; i < stringsAmount; i++)
	{
		//считывание строки
		str = (char*)realloc(str, (255) * sizeof(char));//перераспределение памяти для строки
		size = 0;
		for (; (size < 255) && ((c = fgetc(file)) != '\n'); size++)
		{
			str[size] = c;
		}
		str[size] = '\n';
		size++;
		str[size] = '\0';
		str = (char*)realloc(str, (size + 1) * sizeof(char));//перераспределение памяти для строки

		//запись строки больше заданной длины в список строк
		if (size > strLength)
		{
			strings[strSize].letters = (char*)malloc((size + 1) * sizeof(char));
			memcpy(strings[strSize].letters, str, size + 1);//копируем считанную строку в список строк			
			strSize++;
		}
	}
	strings = (Str*)realloc(strings, (strSize) * sizeof(Str));//перераспределение памяти для списка строк	
	fclose(file);//закрываем поток	
}

void TextFile::writeStringsFromFile(const TextFile& first)//запись набора строк из одного файла в другой
{
	file = fopen(fileName, "w"); //открыть файл для записи; файл создается, если он не существует;
	for (int i = 0; i < first.strSize; i++)
	{
		fputs(first.strings[i].letters, file);//запись строки в файл
	}
	fclose(file);//закрываем поток
	puts("Строки записаны в новый файл.");
}

void TextFile::deleteStrings()//удаление набора строк заданной длины из файла
{	
	file = fopen(this->fileName, "r"); //открыть файл для чтения
	char* str = (char*)malloc(255 * sizeof(char));//выделение памяти для строки
	str[0] = '\0';
	str[255] = '\0';
	strSize = 0;
	strings = (Str*)malloc((stringsAmount) * sizeof(Str));//выделение памяти для списка строк
	char c;
	//составление списка строк меньше заданной длины
	for (int i = 0; i < stringsAmount; i++)
	{
		//считывание строки
		str = (char*)realloc(str, (255) * sizeof(char));//перераспределение памяти для строки
		int size = 0;
		for (; (size < 255) && ((c = fgetc(file)) != '\n'); size++)
		{
			str[size] = c;
		}
		str[size] = '\n';
		size++;
		str[size] = '\0';
		str = (char*)realloc(str, (size + 1) * sizeof(char));//перераспределение памяти для строки

		//запись строки меньше заданной длины в список строк
		if (size <= strLength)
		{
			strings[strSize].letters = (char*)malloc((size + 1) * sizeof(char));
			memcpy(strings[strSize].letters, str, size + 1);//копируем считанную строку в список строк
			strSize++;
		}
	}
	strings = (Str*)realloc(strings, (strSize) * sizeof(Str));//перераспределение памяти для списка строк	
	fclose(file);//закрываем поток

	//перезапись файла с новым списком строк
	file = fopen(fileName, "w"); //открыть файл для записи; файл создается, если он не существует;
	for (int i = 0; i < strSize; i++)
	{
		fputs(strings[i].letters, file);
	}
	fclose(file);//закрываем поток
	puts("Начальный файл перезаписан.");

}

TextFile::~TextFile()//очищение памяти
{
	free(fileName);//очищение имени файла
	free(strings);//очищение массива строк
}
