#include <cstdio>
#pragma once
class InfoBase
{
	const int MAX_FIO_LENGTH = 255; //������������ ����� �������
	const int MAX_DOLGH_LENGTH = 255; //������������ ����� �������� ���������
	int countEmployees;//���������� �����������

	FILE* fioFile; //����� ������� � ����� �� ������� ������� �����������

	FILE* dolghFile; //����� ������� � ����� �� ������� ���������� �����������

	FILE* linkFile; //����� ������� � ����� �� ������� ������ ������� � ����������� �����������

	int dolghAmount; //���������� ����������

	
	struct link{
		unsigned long int name_idx; //������� ������� � �����
		unsigned long int post_idx; //������� ��������� � �����
	} ;//c���� ������� � ����������
	
	int addFio(); //���������� �������

public:
	InfoBase(); //�������� �������������� ����	
	void addDolghs(); //���������� ����������
	void addEmployeesToBase(); //���������� ���������
	void outputEmployeeInfo(int num); //����� ���������� � ���������� �� ���������� ����������� ������
	~InfoBase(); //�������� �������������� ����
};

