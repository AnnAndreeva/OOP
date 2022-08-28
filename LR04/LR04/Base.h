#include <string>
#include <vector>
#pragma once

using namespace std;
class Base
{
	struct Sensor //Датчик
	{
		int sensorCipher;//шифр датчика – трёхзначные целые числа. 
		string sensorName;//название датчика – символьные строки переменной длины
	};

	struct Subsystem//Подсистема
	{
		int subsystemCipher;//шифр подсистемы - двузначные целые числа
		string subsystemName;//название подсистемы – символьные строки произвольной длины
	}; 

	struct Link//Связь датчика с подсистемой
	{
		Sensor* indexOfSensor;//индекс записи в списке датчиков - это указатель записи в памяти
		int indexOfSubsystem;//индекс записи в списке подсистем - это порядковый номер записи в списке
	};

	vector <Sensor> vectorOfSensors;//список датчиков
	vector <Subsystem> vectorOfSubsystems;//список подсистем
	vector <Link> vectorOfLinks;//список связей датчиков с подсистемами


	void getSensor(int num);//получить из списка датчиков информацию о датчике
	void getSubsystem(int num);//получить из списка подсистем информацию о подсистеме
	void getLink(int num);//получить из списка связей информацию о связи


public:
	void addSensorToList();//записать в список датчиков новый датчик
	void addSubsystemToList();//записать в список подсистем новую подсистему
	void addLinkToList();//записать в список связей датчиков с подсистемами новую связь
	

	void deleteLink();//удалить связь между датчиком и подсистемой по индексу в списке связей

	void deleteSubsystem(int num);//удалить из списка подсистем нужную подсистему

	void deleteSensors();//удалить из списка датчиков неиспользуемые датчики

	void outputSubsystems();//вывод на экран названий подсистем, без датчиков
	
};

