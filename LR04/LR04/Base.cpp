#include "Base.h"
#include <string>
#include <vector>
#include <iostream>
#pragma once

using namespace std;
string ex;//c�������� �� ������

void Base::addSensorToList()//�������� � ������ �������� ����� ������
{
	cout << "���������� �������." << endl;
	Sensor sens;
	
	cout << "������� ���� �������: ";
	cin >> sens.sensorCipher; //��������� ����
	cout << "������� �������� �������: ";
	cin >> sens.sensorName; //��������� ��������
	cout << endl;
	if ((sens.sensorCipher > 99) && (sens.sensorCipher < 1000)) { //���������, �������� �� ���� �����������
		vectorOfSensors.push_back(sens);//��������� ������ � ����� ������ ��������
	}
	else throw ex = "���� ������ ���� ����������� ������.";

}

void Base::addSubsystemToList()//�������� � ������ ��������� ����� ����������
{
	cout << "���������� ����������." << endl;
	Subsystem subs;

	cout << "������� ���� ����������: ";
	cin >> subs.subsystemCipher;//��������� ����
	cout << "������� �������� ����������: ";
	cin >> subs.subsystemName;//��������� ��������
	cout << endl;
	if ((subs.subsystemCipher > 9) && (subs.subsystemCipher < 100)) {//���������, �������� �� ���� ����������
		vectorOfSubsystems.push_back(subs);//��������� ���������� � ����� ������ ���������
	}
	else throw ex = "���� ������ ���� ���������� ������.";
}

void Base::addLinkToList() //�������� � ������ ������ �������� � ������������ ����� �����
{
	if (!vectorOfSensors.empty()) {//���������, ���� �� �������
		int numSens, numSub;
		Sensor sens;

		cout << "\n�������:" << endl;
		for (int i = 0; i < vectorOfSensors.size(); i++) { //����� ���� ��������
			cout << "� " << i << ". ";
			getSensor(i);
		}

		cout << "������� ����� �������, ������� ������ ������� � �����������:" << endl;
		cin >> numSens;

		if (numSens < vectorOfSensors.size()) { //���������, ���� �� ������ � ����� ��������

			if (!vectorOfSubsystems.empty()) {//���������, ���� �� ����������
				Link link;

				for (int i = 0; i < vectorOfSubsystems.size(); i++) {//����� ���� ���������
					cout << "� " << i << ". ";
					getSubsystem(i);
				}

				cout << "\n������� ����� ����������, ������� ������ ������� � ��������:" << endl;
				cin >> numSub;

				if (numSub < vectorOfSubsystems.size()) { //���������, ���� �� ���������� � ����� ��������

					link.indexOfSensor = &vectorOfSensors.at(numSens);
					link.indexOfSubsystem = numSub;
					vectorOfLinks.push_back(link);//��������� ����� ������� � ���������� � ����� ������ ������
				}
				else throw ex = "���������� � ����� ������� ���.";
			}
			else throw ex = "��������� ��� ����� ���.";
		}
		else throw ex = "������� � ����� ������� ���.";
	}
	else throw ex = "�������� ��� ����� ���.";
}

void Base::getSensor(int num)//�������� �� ������ �������� ���������� � �������
{
	cout << "����: "
		<< vectorOfSensors.at(num).sensorCipher << "; "//�������� ���� �������
		<< "��������: "
		<< vectorOfSensors.at(num).sensorName << endl;//�������� �������� �������
}

void Base::getSubsystem(int num)//�������� �� ������ ��������� ���������� � ����������
{
	cout << "����: "
		<< vectorOfSubsystems.at(num).subsystemCipher << "; " //�������� ���� ����������
		<< "��������: "
		<< vectorOfSubsystems.at(num).subsystemName << endl; //�������� �������� ����������
}

void Base::getLink(int num)//�������� �� ������ ��������� ���������� � �����
{
	cout << "���� �������: "
		<< vectorOfLinks.at(num).indexOfSensor->sensorCipher << "; "//�������� ���� �������, ���������� � �����������
		<< "���� ����������: "
		<< vectorOfSubsystems.at(vectorOfLinks.at(num).indexOfSubsystem).subsystemCipher << endl;//�������� ���� ����������, ��������� � ��������
}

void Base::deleteLink() // ������� ����� ����� �������� � ����������� �� ������� � ������ ������
{
	if (!vectorOfLinks.empty()) { //���������, ���� �� �����

		cout << "\n����� �������� � ���������:" << endl;
		for (int i = 0; i < vectorOfLinks.size(); i++) { //����� ���� ������

			cout << "� " << i << ". ";
			getLink(i);
		}

		int num;
		cout << "\n������� ����� �����, ������� ������ �������:" << endl;
		cin >> num;

		if (num < vectorOfLinks.size()) { //���������, ���� �� ����� � ����� ��������

			auto it = vectorOfLinks.begin();//��������
			for (int k = 0; k < num; k++, it++) {}//�������� ��������
			vectorOfLinks.erase(it);//������� ����� �� ������� it �� ������ ������
			cout << "\n����� �������." << endl;
		}
		else throw ex = "����� � ����� ������� ���.";
	}
	else throw ex = "������ �������� � ��������� ���.";
}

void Base::deleteSubsystem(int num) //������� �� ������ ��������� ������ ����������
{
	if (!vectorOfSubsystems.empty()) { //���������, ���� �� ����������

		if (num < vectorOfSubsystems.size()) { //���������, ���� �� ���������� � ����� ��������
			cout << "\n��������� ����������:" << endl;
			auto it = vectorOfSubsystems.begin();//�������� ��� ���������
			for (int i = 0; i < num; i++, it++) {}//�������� �������� ��� ���������
			getSubsystem(num);

			vector <int> countOfLinks;//������ ������ � ���� �����������

			for (int j = 0; j < vectorOfLinks.size(); j++) { //������������ ���-�� ������ � ��������� ����������� � ���������� �� �������
				if (vectorOfLinks.at(j).indexOfSubsystem == num) {
					countOfLinks.push_back(vectorOfLinks.size() - j); //���������� ������ ����� ��� �������� � ����� ������ cdzptq
				}
			}

			for (auto el : countOfLinks) { //������� ����� � ���� ����������� 
				auto iter = vectorOfLinks.end(); //�������� ��� ������
				for (int k = el; k > 0; k--, iter--) {}//�������� �������� ��� ������
				vectorOfLinks.erase(iter);//������� ����� � ������ ����������� �� ������ ������ �� ������� iter
			}

			vectorOfSubsystems.erase(it);//������� ���������� �� ������ ���������  �� ������� it
			cout << "\n���������� �������." << endl;
		}
		else throw ex = "��������� � ����� ������� ���.";
	}
	else throw ex = "��������� ���.";
}

void Base::deleteSensors() //������� �� ������ �������� �������������� �������
{
	if (vectorOfLinks.empty()) {//���������, ���� �� �����
		cout << "���� ������� ��� �������, �.�. ����������� �����." << endl;
		vectorOfSensors.clear();//�������� ���� �������� �� ������ 
	}
	else {
		
		vector <int> countOfSensors;//������ �������� ��� ��������

		if (!vectorOfSensors.empty()) {
			for (int i = 0; i < vectorOfSensors.size(); i++) {

				for (int j = 0; j < vectorOfLinks.size(); j++) { //������������ ���-�� �������� ��� �������� � ���������� �� �������

					if (vectorOfSensors.at(i).sensorCipher != vectorOfLinks.at(j).indexOfSensor->sensorCipher) {
						
						countOfSensors.push_back(vectorOfSensors.size() - i); //���������� ������ ������� ��� �������� � ����� ������ ��������
					}
				}
			}
			if (!countOfSensors.empty()) {
				cout << "���������  �������:" << endl;

				for (auto el : countOfSensors) { //������� ����� � ���� ����������� � ����� ������ ������
					auto it = vectorOfSensors.end(); //��������
					for (int k = el; k > 0; k--, it--) {}//�������� ��������
					getSensor(vectorOfSensors.size() - el);
					vectorOfSensors.erase(it);//������� ������ �� ������ �������� �� ������� it
				}
			}
			else {
				cout << "��� ������� ������������." << endl;
			}
		}
		else throw ex = "�������� ���.";
	}
}

void Base::outputSubsystems() //����� �� ����� �������� ���������, ��� ��������
{
	if (!vectorOfSubsystems.empty()) { //���������, ���� �� ����������
		cout << "�������� ���������:" << endl;
		for (int i = 0; i < vectorOfSubsystems.size(); i++) {
			cout << "� " << i << ". ��������: " << vectorOfSubsystems.at(i).subsystemName << endl; //�������� �������� ����������
		}
	}
	else throw ex = "��������� ���.";
}

