#include <string>
#include <vector>
#pragma once

using namespace std;
class Base
{
	struct Sensor //������
	{
		int sensorCipher;//���� ������� � ���������� ����� �����. 
		string sensorName;//�������� ������� � ���������� ������ ���������� �����
	};

	struct Subsystem//����������
	{
		int subsystemCipher;//���� ���������� - ���������� ����� �����
		string subsystemName;//�������� ���������� � ���������� ������ ������������ �����
	}; 

	struct Link//����� ������� � �����������
	{
		Sensor* indexOfSensor;//������ ������ � ������ �������� - ��� ��������� ������ � ������
		int indexOfSubsystem;//������ ������ � ������ ��������� - ��� ���������� ����� ������ � ������
	};

	vector <Sensor> vectorOfSensors;//������ ��������
	vector <Subsystem> vectorOfSubsystems;//������ ���������
	vector <Link> vectorOfLinks;//������ ������ �������� � ������������


	void getSensor(int num);//�������� �� ������ �������� ���������� � �������
	void getSubsystem(int num);//�������� �� ������ ��������� ���������� � ����������
	void getLink(int num);//�������� �� ������ ������ ���������� � �����


public:
	void addSensorToList();//�������� � ������ �������� ����� ������
	void addSubsystemToList();//�������� � ������ ��������� ����� ����������
	void addLinkToList();//�������� � ������ ������ �������� � ������������ ����� �����
	

	void deleteLink();//������� ����� ����� �������� � ����������� �� ������� � ������ ������

	void deleteSubsystem(int num);//������� �� ������ ��������� ������ ����������

	void deleteSensors();//������� �� ������ �������� �������������� �������

	void outputSubsystems();//����� �� ����� �������� ���������, ��� ��������
	
};

