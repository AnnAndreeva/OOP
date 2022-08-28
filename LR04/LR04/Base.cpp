#include "Base.h"
#include <string>
#include <vector>
#include <iostream>
#pragma once

using namespace std;
string ex;//cообщение об ошибке

void Base::addSensorToList()//записать в список датчиков новый датчик
{
	cout << "Добавление датчика." << endl;
	Sensor sens;
	
	cout << "Введите шифр датчика: ";
	cin >> sens.sensorCipher; //считываем шифр
	cout << "Введите название датчика: ";
	cin >> sens.sensorName; //считываем название
	cout << endl;
	if ((sens.sensorCipher > 99) && (sens.sensorCipher < 1000)) { //проверяем, является ли шифр трехзначным
		vectorOfSensors.push_back(sens);//добавляем датчик в конец списка датчиков
	}
	else throw ex = "Шифр должен быть трехзначным числом.";

}

void Base::addSubsystemToList()//записать в список подсистем новую подсистему
{
	cout << "Добавление подсистемы." << endl;
	Subsystem subs;

	cout << "Введите шифр подсистемы: ";
	cin >> subs.subsystemCipher;//считываем шифр
	cout << "Введите название подсистемы: ";
	cin >> subs.subsystemName;//считываем название
	cout << endl;
	if ((subs.subsystemCipher > 9) && (subs.subsystemCipher < 100)) {//проверяем, является ли шифр двузначным
		vectorOfSubsystems.push_back(subs);//добавляем подсистему в конец списка подсистем
	}
	else throw ex = "Шифр должен быть двузначным числом.";
}

void Base::addLinkToList() //записать в список связей датчиков с подсистемами новую связь
{
	if (!vectorOfSensors.empty()) {//проверяем, есть ли датчики
		int numSens, numSub;
		Sensor sens;

		cout << "\nДатчики:" << endl;
		for (int i = 0; i < vectorOfSensors.size(); i++) { //вывод всех датчиков
			cout << "№ " << i << ". ";
			getSensor(i);
		}

		cout << "Введите номер датчика, который хотите связать с подсистемой:" << endl;
		cin >> numSens;

		if (numSens < vectorOfSensors.size()) { //проверяем, есть ли датчик с таким индексом

			if (!vectorOfSubsystems.empty()) {//проверяем, есть ли подсистемы
				Link link;

				for (int i = 0; i < vectorOfSubsystems.size(); i++) {//вывод всех подсистем
					cout << "№ " << i << ". ";
					getSubsystem(i);
				}

				cout << "\nВведите номер подсистемы, которую хотите связать с датчиком:" << endl;
				cin >> numSub;

				if (numSub < vectorOfSubsystems.size()) { //проверяем, есть ли подсистема с таким индексом

					link.indexOfSensor = &vectorOfSensors.at(numSens);
					link.indexOfSubsystem = numSub;
					vectorOfLinks.push_back(link);//добавляем связь датчика и подсистемы в конец списка связей
				}
				else throw ex = "Подсистемы с таким номером нет.";
			}
			else throw ex = "Подсистем для связи нет.";
		}
		else throw ex = "Датчика с таким номером нет.";
	}
	else throw ex = "Датчиков для связи нет.";
}

void Base::getSensor(int num)//получить из списка датчиков информацию о датчике
{
	cout << "Шифр: "
		<< vectorOfSensors.at(num).sensorCipher << "; "//получаем шифр датчика
		<< "Название: "
		<< vectorOfSensors.at(num).sensorName << endl;//получаем название датчика
}

void Base::getSubsystem(int num)//получить из списка подсистем информацию о подсистеме
{
	cout << "Шифр: "
		<< vectorOfSubsystems.at(num).subsystemCipher << "; " //получаем шифр подсистемы
		<< "Название: "
		<< vectorOfSubsystems.at(num).subsystemName << endl; //получаем название подсистемы
}

void Base::getLink(int num)//получить из списка подсистем информацию о связи
{
	cout << "Шифр датчика: "
		<< vectorOfLinks.at(num).indexOfSensor->sensorCipher << "; "//получаем шифр датчика, связанного с подсистемой
		<< "Шифр подсистемы: "
		<< vectorOfSubsystems.at(vectorOfLinks.at(num).indexOfSubsystem).subsystemCipher << endl;//получаем шифр подсистемы, связанной с датчиком
}

void Base::deleteLink() // удалить связь между датчиком и подсистемой по индексу в списке связей
{
	if (!vectorOfLinks.empty()) { //проверяем, есть ли связи

		cout << "\nСвязи датчиков и подсистем:" << endl;
		for (int i = 0; i < vectorOfLinks.size(); i++) { //вывод всех связей

			cout << "№ " << i << ". ";
			getLink(i);
		}

		int num;
		cout << "\nВведите номер связи, которую хотите удалить:" << endl;
		cin >> num;

		if (num < vectorOfLinks.size()) { //проверяем, есть ли связи с таким индексом

			auto it = vectorOfLinks.begin();//итератор
			for (int k = 0; k < num; k++, it++) {}//сдвигаем итератор
			vectorOfLinks.erase(it);//удаляем связь на позиции it из списка связей
			cout << "\nСвязь удалена." << endl;
		}
		else throw ex = "Связи с таким номером нет.";
	}
	else throw ex = "Связей датчиков и подсистем нет.";
}

void Base::deleteSubsystem(int num) //удалить из списка подсистем нужную подсистему
{
	if (!vectorOfSubsystems.empty()) { //проверяем, есть ли подсистемы

		if (num < vectorOfSubsystems.size()) { //проверяем, есть ли подсистема с таким индексом
			cout << "\nУдаленная подсистема:" << endl;
			auto it = vectorOfSubsystems.begin();//итератор для подсистем
			for (int i = 0; i < num; i++, it++) {}//сдвигаем итератор для подсистем
			getSubsystem(num);

			vector <int> countOfLinks;//список связей с этой подсистемой

			for (int j = 0; j < vectorOfLinks.size(); j++) { //подсчитываем кол-во связей с удаляемой подсистемой и записываем их индексы
				if (vectorOfLinks.at(j).indexOfSubsystem == num) {
					countOfLinks.push_back(vectorOfLinks.size() - j); //записываем индекс связи для удаления с конца списка cdzptq
				}
			}

			for (auto el : countOfLinks) { //удаляем связи с этой подсистемой 
				auto iter = vectorOfLinks.end(); //итератор для связей
				for (int k = el; k > 0; k--, iter--) {}//сдвигаем итератор для связей
				vectorOfLinks.erase(iter);//удаляем связь с данной подсистемой из списка связей на позиции iter
			}

			vectorOfSubsystems.erase(it);//удаляем подсистему из списка подсистем  на позиции it
			cout << "\nПодсистема удалена." << endl;
		}
		else throw ex = "Подсистем с таким номером нет.";
	}
	else throw ex = "Подсистем нет.";
}

void Base::deleteSensors() //удалить из списка датчиков неиспользуемые датчики
{
	if (vectorOfLinks.empty()) {//проверяем, есть ли связи
		cout << "Были удалены все датчики, т.к. отсутствуют связи." << endl;
		vectorOfSensors.clear();//удаление всех датчиков из списка 
	}
	else {
		
		vector <int> countOfSensors;//список датчиков для удаления

		if (!vectorOfSensors.empty()) {
			for (int i = 0; i < vectorOfSensors.size(); i++) {

				for (int j = 0; j < vectorOfLinks.size(); j++) { //подсчитываем кол-во датчиков для удаления и записываем их индексы

					if (vectorOfSensors.at(i).sensorCipher != vectorOfLinks.at(j).indexOfSensor->sensorCipher) {
						
						countOfSensors.push_back(vectorOfSensors.size() - i); //записываем индекс датчика для удаления с конца списка датчиков
					}
				}
			}
			if (!countOfSensors.empty()) {
				cout << "Удаленные  датчики:" << endl;

				for (auto el : countOfSensors) { //удаляем связи с этой подсистемой с конца списка связей
					auto it = vectorOfSensors.end(); //итератор
					for (int k = el; k > 0; k--, it--) {}//сдвигаем итератор
					getSensor(vectorOfSensors.size() - el);
					vectorOfSensors.erase(it);//удаляем датчик из списка датчиков на позиции it
				}
			}
			else {
				cout << "Все датчики используются." << endl;
			}
		}
		else throw ex = "Датчиков нет.";
	}
}

void Base::outputSubsystems() //вывод на экран названий подсистем, без датчиков
{
	if (!vectorOfSubsystems.empty()) { //проверяем, есть ли подсистемы
		cout << "Названия подсистем:" << endl;
		for (int i = 0; i < vectorOfSubsystems.size(); i++) {
			cout << "№ " << i << ". Название: " << vectorOfSubsystems.at(i).subsystemName << endl; //получаем название подсистемы
		}
	}
	else throw ex = "Подсистем нет.";
}

