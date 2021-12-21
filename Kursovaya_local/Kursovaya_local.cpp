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
	string error;
	int temp;
	/*
	file_stream.path = "kino_v_teatre.txt\0";
	file_stream.File_write(kinoteatr);
	*/
    do
    {
        system("cls");
		cout << error << "\n\n";
        Menu.File_choice(2);
		start1:
		file_stream.path = "kino_v_teatre.txt\0";
        Menu.Input_number();
		if (Menu.menu_number == 2)	//ввод своего имени файла с кинотеатром
		{
			system("cls");
			file_stream.File_input();
		}
		else if (Menu.menu_number == 3)
		{
			if (Menu.Input_password() == 1)
			{
				system("cls");
				Menu.File_choice(1);
				goto start1;
			}
		}
		else if (Menu.menu_number == 4)
		{
			//создание нового файла под запрос, заполнение всех данных 
		}
		temp = file_stream.File_check();
		if (temp == 1)	//проверка на существование файла с таким названием
		{
			if (file_stream.File_check_compound(&kinoteatr.kol_vo_filmov) == 1)		//проверка файла на внутренее форматирование
			{
				//cout << kinoteatr.kol_vo_filmov;	//тест
				//cout << "Проверку прошел!";	//тест
				file_stream.File_read(&kinoteatr);	//чтение фильмов в массивчик
			}
			else
			{
				error = "В файле \"" + file_stream.path + "\" имеются ошибки";
			}
		}
		else if (temp == 2)
		{
			error = "Файл \"" + file_stream.path + "\" не был найден";
		}
		//_getch();	//тест
		//cout << kinoteatr.filmi[0].name;
		//_getch();
	} while (file_stream.File_check() == 2);

	/// 
	/// ДОБАВИТЬ ДЛЯ ВСЕХ РЕЖИМОВ ВОЗМОЖНОСТЬ СМЕНЫ ТЕКСТОВИКА С БАЗОЙ
	/// 
	/// 
	
	
	do
	{
		Menu.User_kassir();
		Menu.Input_number();
		
		if (Menu.menu_number == 1)
		{
			Menu.Spisok_kino(kinoteatr);	//Выбор фильма для посещения
			Menu.Input_number();
			Menu.num_film = Menu.menu_number;
			Menu.num_day = -1;
			if (Menu.menu_number != 0)	//переход к описанию фильма
			{
				Menu.num_time = -1;
				Menu.Opisanie(kinoteatr);	//ввод даты посещения
				Menu.Input_number();
				Menu.num_day = Menu.menu_number;	//день на покупку/бронь билета
				
				Menu.Opisanie(kinoteatr);	//ввод времени посещения
				Menu.Input_number();
				Menu.num_time = Menu.menu_number;

				Menu.Opisanie(kinoteatr);	//вывод мест в кинотеатре
				///
				///обработка введеного места
				///
				/// 
				_getch();
			}
		}
		else if (Menu.menu_number == 2)
		{
			//ввод пароля на режим администратора
			
			if (Menu.Input_password() == 1)
			{
				//загрузка окна администратора
				Menu.Administrator();
				Menu.Input_number();
				if (Menu.menu_number == 1)
				{
					Menu.Edit_cinema();
					Menu.Input_number();
					if (Menu.menu_number == 1)
					{
						kinoteatr.New_name();
						//запись обновленных данных в файл
					}
				}
			}
		}
	} while (Menu.menu_number != 0);
}

