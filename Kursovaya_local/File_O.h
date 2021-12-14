#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Kinoteatr.h"
using namespace std;

class File_O
{

public:
	int error;
	int kol_vo_film;
	string path;


	void file_input();		//ввод пути для файла
	void file_new();	//создание нового файла
	int file_check(string path);	//проверка на сущестование
	void file_read(string path, Kinoteatr kinoteatr);
	int file_check_compound(string path, int kol_vo);	//проверка форматирования файла
};

