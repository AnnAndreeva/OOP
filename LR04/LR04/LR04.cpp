#include <iostream>
#include "Base.h"

int main()
{
	setlocale(0, "");//Разрешить кириллицу
	puts("Лабораторная работа №3. Вариант №4.");
	puts("Выполнила: Андреева А.А., группа 6213-020302D");
	puts("------------------------------------------------------------------- ");
	Base base = Base();

	int count = 0;
	cout << "Введите количество датчиков для добавления: " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		try
		{
			base.addSensorToList();
		}
		catch (string s) {
			cout << s << endl;
		}
		catch (...) {
			cout << "Ошибка создания датчика. " << endl;
		}
	}

	puts("------------------------------------------------------------------- ");
	cout << "Введите количество подсистем для добавления: " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		try
		{
			base.addSubsystemToList();
		}
		catch (string s) {
			cout << s << endl;
		}
		catch (...) {
			cout << "Ошибка создания подсистемы. " << endl;
		}
	}

	puts("------------------------------------------------------------------- ");
	cout << "Введите количество связей датчиков и подсистем для добавления: " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		try
		{
			base.addLinkToList();
		}
		catch (string s) {
			cout << s << endl;
		}
		catch (...) {
			cout << "Ошибка создания связи. " << endl;
		}
	}

	puts("------------------------------------------------------------------- ");
	cout << "Удалите связь датчика и подсистемы: " << endl;
	try
	{
		base.deleteLink();
	}
	catch (string s) {
		cout << s << endl;
	}
	catch (...) {
		cout << "Ошибка удаления связи. " << endl;
	}

	puts("------------------------------------------------------------------- ");
	cout << "Введите номер подсистемы, которую хотите удалить: " << endl;
	cin >> count;
	try
	{
		base.deleteSubsystem(count);
	}
	catch (string s) {
		cout << s << endl;
	}
	catch (...) {
		cout << "Ошибка удаления подсистемы. " << endl;
	}

	puts("------------------------------------------------------------------- ");
	cout << "Удаление неиспользованных датчиков. " << endl;
	try
	{
		base.deleteSensors();
	}
	catch (string s) {
		cout << s << endl;
	}
	catch (...) {
		cout << "Ошибка удаления датчиков. " << endl;
	}

	puts("------------------------------------------------------------------- ");
	cout << "Названия всех подсистем. " << endl;
	try
	{
		base.outputSubsystems();
	}
	catch (string s) {
		cout << s << endl;
	}
	catch (...) {
		cout << "Ошибка вывода информации о подсистемах. " << endl;
	}
	system("pause");//Задержать консоль на экране при завершении программы
	return 0;

}
