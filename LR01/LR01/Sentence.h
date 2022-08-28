#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Sentence
{
	class Word {
	public:
		char* letters;//����� ��������
	};
	char* sentence;//�����������
	int sentenceSize;//������ �����������

	Word* words;//������ ����
	int wordsSize;//������ ������ ����


	void buildWordsArray();//���������� ������ ���� �� �������
	
	void sort();//c��������� ������ ����

	friend int compareWords(const Sentence::Word* first, const Sentence::Word* second);//��������� ��������� �������� � ������
	
public:
	Sentence();//�������� ������� �����������
	
	explicit Sentence(int i);//�������� �����������
	
	void buildNewSentence(const Sentence& old);//���������� ����������� �� ������ ����

	~Sentence();//������� ������

	void output();//����� �����������
};