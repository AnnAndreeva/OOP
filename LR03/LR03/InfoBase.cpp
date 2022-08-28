#define _CRT_SECURE_NO_WARNINGS
#include "InfoBase.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

InfoBase::InfoBase()//создание информационной базы
{
	//считываем имя файла с фамилиями
	puts("Введите имя файла cо списком фамилий:");//FIO.DAT
	char* tempName = (char*)malloc(255 * sizeof(char));//выделение памяти для имени 
	int tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".DAT");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//перераспределение памяти, выделенной  для имени
	char*  fioFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//выделение памяти для имени файла
	memcpy(fioFileName, tempName, tempNameSize);

	//считываем имя файла с должностями
	puts("Введите имя файла cо списком должностей:");//DOLGH.DAT
	tempName = (char*)malloc(255 * sizeof(char));//выделение памяти для имени 
	tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".DAT");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//перераспределение памяти, выделенной  для имени
	char*  dolghFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//выделение памяти для имени файла
	memcpy(dolghFileName, tempName, tempNameSize);

	//считываем имя файла со связями
	puts("Введите имя файла cо связями фамилий с должностями:");//LINK.IDX
	tempName = (char*)malloc(255 * sizeof(char));//выделение памяти для имени 
	tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".IDX");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//перераспределение памяти, выделенной  для имени
	char* linkFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//выделение памяти для имени файла
	memcpy(linkFileName, tempName, tempNameSize);

	countEmployees = 0;

	fioFile = fopen(fioFileName, "ab+");//открываем файл с фамилиями
	dolghFile = fopen(dolghFileName, "ab+");//открываем файл с должностями
	linkFile = fopen(linkFileName, "ab+");//открываем файл со связями
}

int InfoBase::addFio() //добавление фамилии
{
	puts("Введите фамилию сотрудника:");
	//cчитывание фамилии
	char* fio = (char*)malloc(MAX_FIO_LENGTH * sizeof(char));//выделение памяти для строки
	int fioSize = 0;
	for (; (fioSize < MAX_FIO_LENGTH) && ((fio[fioSize] = (char)getchar()) != '\n'); fioSize++)//считывание введенных символов
	{
	}
	fio[fioSize] = '\0';
	fioSize++;
	fio = (char*)realloc(fio, (fioSize) * sizeof(char));//перераспределение памяти для строки
	fwrite(fio, sizeof(char), fioSize, fioFile);
	return fioSize;//возвращаем длину фамили для индекса
}

void InfoBase::addDolghs()//добавление должностей
{
	int num;
	//считывание количества строк
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//перераспределение памяти
	amount[size - 1] = '\0';
	num = strtol(amount, nullptr, 10);//преобразование в int

	char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//выделение памяти для должности
	int dolghSize = 0;
	char c;

	char* dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//выделение памяти для должности в файле
	bool dolghAdd = false;

	for (int i = 0; i < num; i++) {
		puts("Введите должность:");
		//считываем дожность
		dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//выделение памяти для имени 
		dolghSize = 0;
		for (; (dolghSize < MAX_DOLGH_LENGTH) && ((c = (char)getchar()) != '\n'); dolghSize++)//считывание введенных символов
		{
			dolgh[dolghSize] = c;
		}
		dolgh[dolghSize] = '\0';
		dolghSize++;
		dolgh = (char*)realloc(dolgh, (dolghSize) * sizeof(char));//перераспределение памяти для строки

		dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
		size;
		dolghAdd = false;

		fseek(dolghFile, 0, SEEK_SET);//устанавливаем указатель на начало файла

		while (dolghAdd == false) //пока не добавили должность
		{
			//считывание строки
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//перераспределение памяти для строки
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//перераспределение памяти для строки

			//проверка на наличие должности
			if (feof(dolghFile))//если конец файла
			{
				fseek(dolghFile, 0, SEEK_END);//устанавливаем указатель в конец файла
				fwrite(dolgh, sizeof(char), dolghSize, dolghFile);
				dolghAdd = true;
				puts("Должность добавлена.");
			}
			else {
				
				if (strcmp(dolghInFile, dolgh) == 0)//если должности совпали
				{
					puts("Должность уже существует.");
					dolghAdd = true;
				}
			}
		}
	}
}

void InfoBase::addEmployeesToBase()//добавление сотрудников
{
	int num;//количество сотрудников
	struct link id;//cтруктура связи
	
	//считывание количества сотрудников
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//считывание введенных символов
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//перераспределение памяти
	amount[size - 1] = '\0';
	num = strtol(amount, nullptr, 10);//преобразование в int

	char* dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
	int f = 0;
	char c;
	bool dolghAdd = false;

	//добавление некоторого сотрудников
	for (int j = 0; j < num; j++) {
		int fioSize = addFio();
		id.name_idx = ftell(fioFile) - fioSize;//записываем индекс имени

		printf("\nВыберите должность сотрудника:\n");

		dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
		f = 0;
		dolghAdd = false;

		fseek(dolghFile, 0, SEEK_SET);//устанавливаем указатель на начало файла

		//считываем кол-во должностей
		while (dolghAdd == false)
		{
			//считывание строки
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//перераспределение памяти для строки
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//перераспределение памяти для строки
			f++;
			if (feof(dolghFile))
			{
				dolghAdd = true;
			}
		}
		f--;

		fseek(dolghFile, 0, SEEK_SET);//устанавливаем указатель на начало файла
		//считываем должности и выводим на экран
		for (int i = 0; i < f; i++)
		{
			//считывание строки
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//перераспределение памяти для строки
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//перераспределение памяти для строки
			printf(dolghInFile);
			printf("\n");
		}

		//считываем введёную должность
		printf("Введите название выбранной должности:\n");
		char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//выделение памяти для имени 
		int dolghSize = 0;
		for (; (dolghSize < MAX_DOLGH_LENGTH) && ((c = (char)getchar()) != '\n'); dolghSize++)//считывание введенных символов
		{
			dolgh[dolghSize] = c;
		}
		dolgh[dolghSize] = '\0';
		dolghSize++;
		dolgh = (char*)realloc(dolgh, (dolghSize) * sizeof(char));//перераспределение памяти для строки

		dolghAdd = false;

		//добавляем сотрудника
		fseek(dolghFile, 0, SEEK_SET);//устанавливаем указатель на начало файла
		while (dolghAdd == false)
		{
			//считывание строки
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//перераспределение памяти для строки
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//перераспределение памяти для строки


			if (strcmp(dolghInFile, dolgh) == 0)//если строка из файла совпала со считанной строкой 
			{
				id.post_idx = ftell(dolghFile) - size;//записываем индекс должности

				fseek(linkFile, 0, SEEK_END);//устанавливаем указатель на начало файла

				//записываем индексы в файл
				char* idx = (char*)malloc(10 * sizeof(char));
				_ltoa(id.name_idx, idx, 10);
				fwrite(idx, sizeof(char), strlen(idx), linkFile);
				fwrite(" ", sizeof(char), 1, linkFile);

				idx = (char*)realloc(idx, 10 * sizeof(char));
				_ltoa(id.post_idx, idx, 10);
				fwrite(idx, sizeof(char), strlen(idx), linkFile);
				fwrite("\0\n", sizeof(char), 2, linkFile);

				countEmployees++;
				dolghAdd = true;
				printf("Сотрудник добавлен.\n");
			}
			if (feof(dolghFile)) {//если конец файла 
				dolghAdd = true;
				printf("Такой должности нет.\n");
			}
		}		
	}
}

void InfoBase::outputEmployeeInfo(int num)//вывод информации о сотруднике по указанному порядковому номеру
{
	if (num <= countEmployees) {//проверка введенного номера и кол-ва должностей
		char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//выделение памяти для должности
		char* fio = (char*)malloc(MAX_FIO_LENGTH * sizeof(char));//выделение памяти для фамилии 
		long int name_idx = 0, post_idx = 0;

		fseek(linkFile, 0, SEEK_SET);//устанавливаем указатель на начало файла
		char* ind = (char*)malloc(10 * sizeof(char));//выделение памяти для индекса
		int dolghSize = 0, fioSize = 0;
		char c;
		for (int i = 0; i < num; i++) {//поиск по индексному файлу строки с нужным номером
			ind[0] = '\0';
			fioSize = 0;
			//считываем индекс фамилии
			for (; (fioSize < 10) && ((c = fgetc(linkFile)) != ' '); fioSize++)
			{
				ind[fioSize] = c;
			}
			ind = (char*)realloc(ind, (fioSize) * sizeof(char));//перераспределение памяти для строки
			name_idx = atol(ind);//индекс фамилии

			dolghSize = 0;
			ind[0] = '\0';
			//считываем индекс должности
			for (; (dolghSize < 10) && ((c = fgetc(linkFile)) != '\n'); dolghSize++)
			{
				ind[dolghSize] = c;
			}
			ind = (char*)realloc(ind, (dolghSize--) * sizeof(char));//перераспределение памяти для строки
			post_idx = atol(ind);//индекс должности
		}
		fseek(fioFile, name_idx, SEEK_SET);//устанавливаем указатель в файле на нужную фамилию
		fread(fio, sizeof(char), MAX_FIO_LENGTH, fioFile);//считывае нужную фамилию
		fseek(dolghFile, post_idx, SEEK_SET);//устанавливаем указатель в файле на нужную должность
		fread(dolgh, sizeof(char), MAX_DOLGH_LENGTH, dolghFile);//считываем нужную должность

		printf("Сотрудник  %s - должность %s.\n", fio, dolgh);
	}
	else {
		printf("Сотрудника с таким номером не существует.\n");
	}
}

InfoBase::~InfoBase() //удаление информационной базы
{
	fclose(fioFile);//закрываем файл с фамилиями
	fclose(dolghFile);//закрываем файл с должностями
	fclose(linkFile);//закрываем файл со связями
}
