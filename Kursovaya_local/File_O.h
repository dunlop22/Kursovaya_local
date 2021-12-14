#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Kinoteatr.h"
using namespace std;

class File_O
{

public:
	int error;	//номер ошибки
	int kol_vo_film;	//количества фильмов в прокате
	string path;	//файл с данными о кинотеатре


	void File_input();		//ввод пути для файла
	void File_new();	//создание нового файла
	int File_check(string path);	//проверка на сущестование
	void File_read(string path, Kinoteatr kinoteatr);
	int File_check_compound(string path, int kol_vo);	//проверка форматирования файла
};

