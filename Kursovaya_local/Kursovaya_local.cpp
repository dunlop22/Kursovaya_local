#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>
#include "Menu.h"
#include "File_O.h"
#include "Kinoteatr.h"
#include <conio.h>
using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    File_O file_stream;
    Menu Menu;
	Kinoteatr kinoteatr;
    do
    {
        system("cls");
        Menu.File_choice(2);
        Menu.Input_number();
		if (Menu.menu_number == 2)	//ввод своего имени файла с кинотеатром
		{
			file_stream.File_input();
		}

		file_stream.path = "kino_v_teatre.txt\0";
		if (file_stream.File_check(file_stream.path))	//проверка на существование файла с таким названием
		{
			if (file_stream.File_check_compound(file_stream.path, &kinoteatr.kol_vo_filmov) == 1)		//проверка файла на внутренее форматирование
			{
				//cout << kinoteatr.kol_vo_filmov;	//тест
				//cout << "Проверку прошел!";	//тест
				file_stream.File_read(file_stream.path, &kinoteatr);	//чтение фильмов в массивчик
			}
		}
		//_getch();	//тест
		//cout << kinoteatr.filmi[0].name;
		//_getch();
	} while (file_stream.File_check(file_stream.path) != 1);
}

