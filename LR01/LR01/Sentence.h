#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Sentence
{
	class Word {
	public:
		char* letters;//набор символов
	};
	char* sentence;//предложение
	int sentenceSize;//размер предложения

	Word* words;//список слов
	int wordsSize;//размер списка слов


	void buildWordsArray();//построение списка слов по заданию
	
	void sort();//cортировка списка слов

	friend int compareWords(const Sentence::Word* first, const Sentence::Word* second);//сравнение последних символов в словах
	
public:
	Sentence();//создание пустого предложения
	
	explicit Sentence(int i);//создание предложения
	
	void buildNewSentence(const Sentence& old);//построение предложения из списка слов

	~Sentence();//очистка памяти

	void output();//вывод предложения
};