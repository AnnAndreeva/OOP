#define _CRT_SECURE_NO_WARNINGS
#include "InfoBase.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

InfoBase::InfoBase()//�������� �������������� ����
{
	//��������� ��� ����� � ���������
	puts("������� ��� ����� c� ������� �������:");//FIO.DAT
	char* tempName = (char*)malloc(255 * sizeof(char));//��������� ������ ��� ����� 
	int tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".DAT");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//����������������� ������, ����������  ��� �����
	char*  fioFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//��������� ������ ��� ����� �����
	memcpy(fioFileName, tempName, tempNameSize);

	//��������� ��� ����� � �����������
	puts("������� ��� ����� c� ������� ����������:");//DOLGH.DAT
	tempName = (char*)malloc(255 * sizeof(char));//��������� ������ ��� ����� 
	tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".DAT");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//����������������� ������, ����������  ��� �����
	char*  dolghFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//��������� ������ ��� ����� �����
	memcpy(dolghFileName, tempName, tempNameSize);

	//��������� ��� ����� �� �������
	puts("������� ��� ����� c� ������� ������� � �����������:");//LINK.IDX
	tempName = (char*)malloc(255 * sizeof(char));//��������� ������ ��� ����� 
	tempNameSize = 0;
	for (; (tempNameSize < 255) && ((tempName[tempNameSize++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	tempName[tempNameSize - 1] = '\0';
	strcat(tempName, ".IDX");
	tempNameSize += 4;
	tempName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//����������������� ������, ����������  ��� �����
	char* linkFileName = (char*)realloc(tempName, (tempNameSize) * sizeof(char));//��������� ������ ��� ����� �����
	memcpy(linkFileName, tempName, tempNameSize);

	countEmployees = 0;

	fioFile = fopen(fioFileName, "ab+");//��������� ���� � ���������
	dolghFile = fopen(dolghFileName, "ab+");//��������� ���� � �����������
	linkFile = fopen(linkFileName, "ab+");//��������� ���� �� �������
}

int InfoBase::addFio() //���������� �������
{
	puts("������� ������� ����������:");
	//c��������� �������
	char* fio = (char*)malloc(MAX_FIO_LENGTH * sizeof(char));//��������� ������ ��� ������
	int fioSize = 0;
	for (; (fioSize < MAX_FIO_LENGTH) && ((fio[fioSize] = (char)getchar()) != '\n'); fioSize++)//���������� ��������� ��������
	{
	}
	fio[fioSize] = '\0';
	fioSize++;
	fio = (char*)realloc(fio, (fioSize) * sizeof(char));//����������������� ������ ��� ������
	fwrite(fio, sizeof(char), fioSize, fioFile);
	return fioSize;//���������� ����� ������ ��� �������
}

void InfoBase::addDolghs()//���������� ����������
{
	int num;
	//���������� ���������� �����
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//����������������� ������
	amount[size - 1] = '\0';
	num = strtol(amount, nullptr, 10);//�������������� � int

	char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//��������� ������ ��� ���������
	int dolghSize = 0;
	char c;

	char* dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//��������� ������ ��� ��������� � �����
	bool dolghAdd = false;

	for (int i = 0; i < num; i++) {
		puts("������� ���������:");
		//��������� ��������
		dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//��������� ������ ��� ����� 
		dolghSize = 0;
		for (; (dolghSize < MAX_DOLGH_LENGTH) && ((c = (char)getchar()) != '\n'); dolghSize++)//���������� ��������� ��������
		{
			dolgh[dolghSize] = c;
		}
		dolgh[dolghSize] = '\0';
		dolghSize++;
		dolgh = (char*)realloc(dolgh, (dolghSize) * sizeof(char));//����������������� ������ ��� ������

		dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
		size;
		dolghAdd = false;

		fseek(dolghFile, 0, SEEK_SET);//������������� ��������� �� ������ �����

		while (dolghAdd == false) //���� �� �������� ���������
		{
			//���������� ������
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//����������������� ������ ��� ������
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//����������������� ������ ��� ������

			//�������� �� ������� ���������
			if (feof(dolghFile))//���� ����� �����
			{
				fseek(dolghFile, 0, SEEK_END);//������������� ��������� � ����� �����
				fwrite(dolgh, sizeof(char), dolghSize, dolghFile);
				dolghAdd = true;
				puts("��������� ���������.");
			}
			else {
				
				if (strcmp(dolghInFile, dolgh) == 0)//���� ��������� �������
				{
					puts("��������� ��� ����������.");
					dolghAdd = true;
				}
			}
		}
	}
}

void InfoBase::addEmployeesToBase()//���������� �����������
{
	int num;//���������� �����������
	struct link id;//c�������� �����
	
	//���������� ���������� �����������
	char* amount = (char*)malloc(255 * sizeof(char));
	int size = 0;
	for (; (size < 255) && ((amount[size++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{
	}
	amount = (char*)realloc(amount, (size) * sizeof(char));//����������������� ������
	amount[size - 1] = '\0';
	num = strtol(amount, nullptr, 10);//�������������� � int

	char* dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
	int f = 0;
	char c;
	bool dolghAdd = false;

	//���������� ���������� �����������
	for (int j = 0; j < num; j++) {
		int fioSize = addFio();
		id.name_idx = ftell(fioFile) - fioSize;//���������� ������ �����

		printf("\n�������� ��������� ����������:\n");

		dolghInFile = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));
		f = 0;
		dolghAdd = false;

		fseek(dolghFile, 0, SEEK_SET);//������������� ��������� �� ������ �����

		//��������� ���-�� ����������
		while (dolghAdd == false)
		{
			//���������� ������
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//����������������� ������ ��� ������
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//����������������� ������ ��� ������
			f++;
			if (feof(dolghFile))
			{
				dolghAdd = true;
			}
		}
		f--;

		fseek(dolghFile, 0, SEEK_SET);//������������� ��������� �� ������ �����
		//��������� ��������� � ������� �� �����
		for (int i = 0; i < f; i++)
		{
			//���������� ������
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//����������������� ������ ��� ������
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//����������������� ������ ��� ������
			printf(dolghInFile);
			printf("\n");
		}

		//��������� ������� ���������
		printf("������� �������� ��������� ���������:\n");
		char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//��������� ������ ��� ����� 
		int dolghSize = 0;
		for (; (dolghSize < MAX_DOLGH_LENGTH) && ((c = (char)getchar()) != '\n'); dolghSize++)//���������� ��������� ��������
		{
			dolgh[dolghSize] = c;
		}
		dolgh[dolghSize] = '\0';
		dolghSize++;
		dolgh = (char*)realloc(dolgh, (dolghSize) * sizeof(char));//����������������� ������ ��� ������

		dolghAdd = false;

		//��������� ����������
		fseek(dolghFile, 0, SEEK_SET);//������������� ��������� �� ������ �����
		while (dolghAdd == false)
		{
			//���������� ������
			dolghInFile = (char*)realloc(dolghInFile, (MAX_DOLGH_LENGTH) * sizeof(char));//����������������� ������ ��� ������
			size = 0;
			for (; (size < MAX_DOLGH_LENGTH) && ((c = fgetc(dolghFile)) != '\0'); size++)
			{
				dolghInFile[size] = c;
			}
			dolghInFile[size] = '\0';
			size++;
			dolghInFile = (char*)realloc(dolghInFile, (size) * sizeof(char));//����������������� ������ ��� ������


			if (strcmp(dolghInFile, dolgh) == 0)//���� ������ �� ����� ������� �� ��������� ������� 
			{
				id.post_idx = ftell(dolghFile) - size;//���������� ������ ���������

				fseek(linkFile, 0, SEEK_END);//������������� ��������� �� ������ �����

				//���������� ������� � ����
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
				printf("��������� ��������.\n");
			}
			if (feof(dolghFile)) {//���� ����� ����� 
				dolghAdd = true;
				printf("����� ��������� ���.\n");
			}
		}		
	}
}

void InfoBase::outputEmployeeInfo(int num)//����� ���������� � ���������� �� ���������� ����������� ������
{
	if (num <= countEmployees) {//�������� ���������� ������ � ���-�� ����������
		char* dolgh = (char*)malloc(MAX_DOLGH_LENGTH * sizeof(char));//��������� ������ ��� ���������
		char* fio = (char*)malloc(MAX_FIO_LENGTH * sizeof(char));//��������� ������ ��� ������� 
		long int name_idx = 0, post_idx = 0;

		fseek(linkFile, 0, SEEK_SET);//������������� ��������� �� ������ �����
		char* ind = (char*)malloc(10 * sizeof(char));//��������� ������ ��� �������
		int dolghSize = 0, fioSize = 0;
		char c;
		for (int i = 0; i < num; i++) {//����� �� ���������� ����� ������ � ������ �������
			ind[0] = '\0';
			fioSize = 0;
			//��������� ������ �������
			for (; (fioSize < 10) && ((c = fgetc(linkFile)) != ' '); fioSize++)
			{
				ind[fioSize] = c;
			}
			ind = (char*)realloc(ind, (fioSize) * sizeof(char));//����������������� ������ ��� ������
			name_idx = atol(ind);//������ �������

			dolghSize = 0;
			ind[0] = '\0';
			//��������� ������ ���������
			for (; (dolghSize < 10) && ((c = fgetc(linkFile)) != '\n'); dolghSize++)
			{
				ind[dolghSize] = c;
			}
			ind = (char*)realloc(ind, (dolghSize--) * sizeof(char));//����������������� ������ ��� ������
			post_idx = atol(ind);//������ ���������
		}
		fseek(fioFile, name_idx, SEEK_SET);//������������� ��������� � ����� �� ������ �������
		fread(fio, sizeof(char), MAX_FIO_LENGTH, fioFile);//�������� ������ �������
		fseek(dolghFile, post_idx, SEEK_SET);//������������� ��������� � ����� �� ������ ���������
		fread(dolgh, sizeof(char), MAX_DOLGH_LENGTH, dolghFile);//��������� ������ ���������

		printf("���������  %s - ��������� %s.\n", fio, dolgh);
	}
	else {
		printf("���������� � ����� ������� �� ����������.\n");
	}
}

InfoBase::~InfoBase() //�������� �������������� ����
{
	fclose(fioFile);//��������� ���� � ���������
	fclose(dolghFile);//��������� ���� � �����������
	fclose(linkFile);//��������� ���� �� �������
}
