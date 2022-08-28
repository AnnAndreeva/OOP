#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include "Sentence.h"
constexpr int maxLenght = 80;//максимальная длина предложения

Sentence::Sentence()//создание пустого предложения
{
	sentenceSize = 1;
	sentence = (char*)malloc(sentenceSize * sizeof(char));//выделение памяти для предложения
	sentence[0] = '\0';
	wordsSize = 0;
	words = (Word*)malloc(sizeof(Word));//выделение памяти для списка слов в предложении
	words[0].letters = nullptr;
}

Sentence::Sentence(int i)//создание заданного предложения
{
	puts("Введите предложение: ");
	sentence = (char*)malloc((maxLenght + 1) * sizeof(char));//выделение памяти для предложения
	sentenceSize = 0;
	for (; (sentenceSize < maxLenght) && ((sentence[sentenceSize++] = (char)getchar()) != '\n');)//считывание введенных символов
	{	}
	sentence = (char*)realloc(sentence, (sentenceSize + 1) * sizeof(char));//удаление лишней памяти, выделенной  для предложения
	sentence[sentenceSize] = '\0';
	buildWordsArray();
}

void Sentence::buildNewSentence(const Sentence& old)//построение предложения из списка слов
{
	//присвоение того же размера, что и у исходного предложения
	sentenceSize = old.sentenceSize + 1;
	//выделение того же кол-ва памяти, что и у исходного предложения
	sentence = (char*)malloc((sentenceSize + 1) * sizeof(char));
	for (int i = 0; i < sentenceSize + 1; ++i)
		sentence[i] = '\0';
	for (int i = 0; i < old.wordsSize; ++i)//добавление тех же слов, что и в исходном предложении
	{
		strcat(sentence, old.words[i].letters);
		strcat(sentence, " ");
	}
}

void Sentence::buildWordsArray()//построение списка слов
{
	const char* delimiter = " \n";
	words = (Word*)malloc((sentenceSize + 1) * sizeof(Word));//выделение памяти для списка слов в предложении
	wordsSize = 0;
	if ((words[wordsSize].letters = strtok(sentence, delimiter)) != nullptr)//считывание кол-ва слов
	{
		++wordsSize;
		while ((words[wordsSize].letters = strtok(nullptr, delimiter)) != nullptr)
		{
			++wordsSize;
		}
	}
	words = (Word*)realloc(words, wordsSize * sizeof(Word));//удаление лишней памяти, выделенной для списка слов
	sort();
}

int compareWords(const Sentence::Word * first, const Sentence::Word * second)//сравнение последних символов в словах 
{
	return (int)((first->letters[strlen(first->letters) - 1] - 'a') - (second->letters[strlen(second->letters) - 1] - 'a'));
}

void Sentence::sort()//cортировка списка слов
{
	qsort(words, wordsSize, sizeof(Word),
		(int(*) (const void*, const void*))compareWords);//быстрая сортировка
}

void Sentence::output()//вывод предложения
{
	puts(sentence);	
}

Sentence::~Sentence()//удаление предложения
{
	free(sentence);
	free(words);
}
