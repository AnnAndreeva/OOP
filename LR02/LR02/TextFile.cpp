#define _CRT_SECURE_NO_WARNINGS
#include "TextFile.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
int strLength;//�����, ���������� �������������

TextFile::TextFile(int i)//�������� �����
{
	puts("������� ��� �����: ");
	char* name = (char*)malloc(255 * sizeof(char));//��������� ������ ��� ����� 
	int nameSize = 0;
	for (; (nameSize < 255) && ((name[nameSize++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	name[nameSize - 1] = '\0';
	strcat(name, ".txt");
	nameSize += 4;
	name = (char*)realloc(name, (nameSize) * sizeof(char));//����������������� ������, ����������  ��� �����
	fileName = (char*)realloc(name, (nameSize) * sizeof(char));//��������� ������ ��� ����� �����
	memcpy(fileName, name, nameSize);
	if (i == 1) {
		inputStrings();
	}

}

void TextFile::inputStrings()//���������� ����� � ����
{
	file = fopen(fileName, "w"); //������� ���� ��� ������; ���� ���������, ���� �� �� ����������;
	if (file == NULL) {
		perror("������ ��� ��������  �����");
	}
	else {
		puts("������� ���������� ����� � �����: ");
		//���������� ���������� �����
		char* amount = (char*)malloc(255 * sizeof(char));
		int size = 0;
		for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//���������� ��������� ��������
		{
		}
		amount = (char*)realloc(amount, (size) * sizeof(char));//����������������� ������
		amount[size - 1] = '\0';
		stringsAmount = strtol(amount, nullptr, 10);//�������������� � int

		char* str = (char*)malloc(255 * sizeof(char));
		puts("������� c�����:");
		for (int i = 0; i < stringsAmount; i++)
		{
			fgets(str, 255, stdin);//���������� ������ � �������
			fprintf(file, str);	 //������ ������ � ����
		}
		fclose(file);//��������� �����
		getStrings();//����������� ������ ����� ������ ����� �� ����� �����
	}
}

void TextFile::getStrings() //����������� ������ ����� �������� ����� �� ����� �����
{
	puts("������� ������ �����, ������� �� ������ �������� � �����: ");
	//���������� ����� �����
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//�������� ������ ������
	amount[size - 1] = '\0';
	strLength = strtol(amount, nullptr, 10);//�������������� � int

	file = fopen(fileName, "r"); //������� ���� ��� ������
	char* str = (char*)malloc(255 * sizeof(char));
	str[0] = '\0';
	str[255] = '\0';
	strSize = 0;
	strings = (Str*)malloc((stringsAmount) * sizeof(Str));//��������� ������ ��� ������ �����
	char c;
	//����������� ������ ����� ������ �������� �����
	for (int i = 0; i < stringsAmount; i++)
	{
		//���������� ������
		str = (char*)realloc(str, (255) * sizeof(char));//����������������� ������ ��� ������
		size = 0;
		for (; (size < 255) && ((c = fgetc(file)) != '\n'); size++)
		{
			str[size] = c;
		}
		str[size] = '\n';
		size++;
		str[size] = '\0';
		str = (char*)realloc(str, (size + 1) * sizeof(char));//����������������� ������ ��� ������

		//������ ������ ������ �������� ����� � ������ �����
		if (size > strLength)
		{
			strings[strSize].letters = (char*)malloc((size + 1) * sizeof(char));
			memcpy(strings[strSize].letters, str, size + 1);//�������� ��������� ������ � ������ �����			
			strSize++;
		}
	}
	strings = (Str*)realloc(strings, (strSize) * sizeof(Str));//����������������� ������ ��� ������ �����	
	fclose(file);//��������� �����	
}

void TextFile::writeStringsFromFile(const TextFile& first)//������ ������ ����� �� ������ ����� � ������
{
	file = fopen(fileName, "w"); //������� ���� ��� ������; ���� ���������, ���� �� �� ����������;
	for (int i = 0; i < first.strSize; i++)
	{
		fputs(first.strings[i].letters, file);//������ ������ � ����
	}
	fclose(file);//��������� �����
	puts("������ �������� � ����� ����.");
}

void TextFile::deleteStrings()//�������� ������ ����� �������� ����� �� �����
{	
	file = fopen(this->fileName, "r"); //������� ���� ��� ������
	char* str = (char*)malloc(255 * sizeof(char));//��������� ������ ��� ������
	str[0] = '\0';
	str[255] = '\0';
	strSize = 0;
	strings = (Str*)malloc((stringsAmount) * sizeof(Str));//��������� ������ ��� ������ �����
	char c;
	//����������� ������ ����� ������ �������� �����
	for (int i = 0; i < stringsAmount; i++)
	{
		//���������� ������
		str = (char*)realloc(str, (255) * sizeof(char));//����������������� ������ ��� ������
		int size = 0;
		for (; (size < 255) && ((c = fgetc(file)) != '\n'); size++)
		{
			str[size] = c;
		}
		str[size] = '\n';
		size++;
		str[size] = '\0';
		str = (char*)realloc(str, (size + 1) * sizeof(char));//����������������� ������ ��� ������

		//������ ������ ������ �������� ����� � ������ �����
		if (size <= strLength)
		{
			strings[strSize].letters = (char*)malloc((size + 1) * sizeof(char));
			memcpy(strings[strSize].letters, str, size + 1);//�������� ��������� ������ � ������ �����
			strSize++;
		}
	}
	strings = (Str*)realloc(strings, (strSize) * sizeof(Str));//����������������� ������ ��� ������ �����	
	fclose(file);//��������� �����

	//���������� ����� � ����� ������� �����
	file = fopen(fileName, "w"); //������� ���� ��� ������; ���� ���������, ���� �� �� ����������;
	for (int i = 0; i < strSize; i++)
	{
		fputs(strings[i].letters, file);
	}
	fclose(file);//��������� �����
	puts("��������� ���� �����������.");

}

TextFile::~TextFile()//�������� ������
{
	free(fileName);//�������� ����� �����
	free(strings);//�������� ������� �����
}
