#include <cstdio>
#pragma once
class InfoBase
{
	const int MAX_FIO_LENGTH = 255; //максимальная длина фамилии
	const int MAX_DOLGH_LENGTH = 255; //максимальная длина названия должности
	int countEmployees;//количество сотрудников

	FILE* fioFile; //поток доступа к файлу со списком фамилий сотрудников

	FILE* dolghFile; //поток доступа к файлу со списком должностей сотрудников

	FILE* linkFile; //поток доступа к файлу со списком связей фамилий с должностями сотрудников

	int dolghAmount; //количество должностей

	
	struct link{
		unsigned long int name_idx; //позиция фамилии в файле
		unsigned long int post_idx; //позиция должности в файле
	} ;//cвязь фамилии с должностью
	
	int addFio(); //добавление фамилии

public:
	InfoBase(); //создание информационной базы	
	void addDolghs(); //добавление должностей
	void addEmployeesToBase(); //добавление сотрудник
	void outputEmployeeInfo(int num); //вывод информации о сотруднике по указанному порядковому номеру
	~InfoBase(); //удаление информационной базы
};

