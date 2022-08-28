#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include "Sentence.h"
constexpr int maxLenght = 80;//������������ ����� �����������

Sentence::Sentence()//�������� ������� �����������
{
	sentenceSize = 1;
	sentence = (char*)malloc(sentenceSize * sizeof(char));//��������� ������ ��� �����������
	sentence[0] = '\0';
	wordsSize = 0;
	words = (Word*)malloc(sizeof(Word));//��������� ������ ��� ������ ���� � �����������
	words[0].letters = nullptr;
}

Sentence::Sentence(int i)//�������� ��������� �����������
{
	puts("������� �����������: ");
	sentence = (char*)malloc((maxLenght + 1) * sizeof(char));//��������� ������ ��� �����������
	sentenceSize = 0;
	for (; (sentenceSize < maxLenght) && ((sentence[sentenceSize++] = (char)getchar()) != '\n');)//���������� ��������� ��������
	{	}
	sentence = (char*)realloc(sentence, (sentenceSize + 1) * sizeof(char));//�������� ������ ������, ����������  ��� �����������
	sentence[sentenceSize] = '\0';
	buildWordsArray();
}

void Sentence::buildNewSentence(const Sentence& old)//���������� ����������� �� ������ ����
{
	//���������� ���� �� �������, ��� � � ��������� �����������
	sentenceSize = old.sentenceSize + 1;
	//��������� ���� �� ���-�� ������, ��� � � ��������� �����������
	sentence = (char*)malloc((sentenceSize + 1) * sizeof(char));
	for (int i = 0; i < sentenceSize + 1; ++i)
		sentence[i] = '\0';
	for (int i = 0; i < old.wordsSize; ++i)//���������� ��� �� ����, ��� � � �������� �����������
	{
		strcat(sentence, old.words[i].letters);
		strcat(sentence, " ");
	}
}

void Sentence::buildWordsArray()//���������� ������ ����
{
	const char* delimiter = " \n";
	words = (Word*)malloc((sentenceSize + 1) * sizeof(Word));//��������� ������ ��� ������ ���� � �����������
	wordsSize = 0;
	if ((words[wordsSize].letters = strtok(sentence, delimiter)) != nullptr)//���������� ���-�� ����
	{
		++wordsSize;
		while ((words[wordsSize].letters = strtok(nullptr, delimiter)) != nullptr)
		{
			++wordsSize;
		}
	}
	words = (Word*)realloc(words, wordsSize * sizeof(Word));//�������� ������ ������, ���������� ��� ������ ����
	sort();
}

int compareWords(const Sentence::Word * first, const Sentence::Word * second)//��������� ��������� �������� � ������ 
{
	return (int)((first->letters[strlen(first->letters) - 1] - 'a') - (second->letters[strlen(second->letters) - 1] - 'a'));
}

void Sentence::sort()//c��������� ������ ����
{
	qsort(words, wordsSize, sizeof(Word),
		(int(*) (const void*, const void*))compareWords);//������� ����������
}

void Sentence::output()//����� �����������
{
	puts(sentence);	
}

Sentence::~Sentence()//�������� �����������
{
	free(sentence);
	free(words);
}
