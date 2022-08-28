#pragma once
#include <cstdio>
#include <iostream>

class TextFile
{
	char* fileName;//��� �����
	FILE* file;//����� ������� � �����
	int stringsAmount;//���-�� ����� � �����
	
	class Str {
	public:
		char* letters;//����� ��������
	};

	Str* strings;//����� ����� �������� �����
	int strSize;//����� ������ �����
	

	void inputStrings();//���������� ����� � ����
	void getStrings();//����������� ������ ����� �������� ����� �� ����� �����
	
	
public:
	TextFile(int i);//�������� �����
	void writeStringsFromFile(const TextFile& first);//������ ������ ����� �� ������ ����� � ������
	void deleteStrings();//�������� ������ ����� �������� ����� �� �����
	~TextFile();//�������� ������
};

