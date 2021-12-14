#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include "Kinoteatr.h"


using namespace std;

/*Menu::Menu()
{ }
Menu::Menu(const char* menu_text, int item_num)
{
	strcpy(this->menu_text, menu_text);
	this->menu_text[511] = '\0';

	this->item_num = item_num;
}

Menu::~Menu()
{
}

void Menu::print()
{
	printf("%s", menu_text);
}
*/

void Menu::Start_menu()
{
	system("cls");
	cout << "Для просмотра списка фильмов нажмите '1'.\nДля входа в режим администратора нажмите '2'.\nДля выхода нажмите 'esc'.\n\n";
	item_num = 2;
}

void Menu::User_kassir()
{
	system("cls");
	cout << "********name_kinofeatre!!!*******\n\n";
	cout << "1) Просмотр списка фильмов\n2) Вход в режим администратора\n\nESC - Выход";
	item_num = 2;
}


void Menu::Input_number()
{
	do
	{
		menu_number = -1;

		char symbol;
		symbol = _getch();

		if (symbol == 27)
		{
			menu_number = 0;
		}
		else if (symbol >= '1' && symbol <= '9')
		{
			menu_number = symbol - 48;
		}

	} while (menu_number < 0 || menu_number > item_num);
}

void Menu::Spisok_kino(Kinoteatr kinoteatr)
{
	system("cls");
	cout << "********name_kinofeatre!!!*******\n\n";
	cout << "0) Возврат в меню\n\n";
	cout << "Список фильмов:\n\n";
	for (int i = 0; i < kinoteatr.kol_vo_filmov; i++)
	{
		cout << i + 1 << ") " << kinoteatr.filmi[i].name << " (" << kinoteatr.filmi[i].age << ")\n";
	}
}



void Menu::Opisanie(Kinoteatr kinoteatr)
{
	
	const time_t tm = time(nullptr);

	char buf[64];
	strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));
	std::cout << buf << std::endl;
			

	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << "\n";
	
	

	system("cls");

	
	
	/*
	cout << "yesterday : " << convTime(yesterday) << endl;
	cout << "present   : " << convTime(present) << endl;
	cout << "tommorow  : " << convTime(tommorow) << endl;
	*/
	Universal uni;

	
	
	cout << "\n\nНазвание: " << kinoteatr.filmi[menu_number - 1].name;
	cout << "\n\nОписание: " << kinoteatr.filmi[menu_number - 1].short_description;
	cout << "\n\nПродолжительность: " << kinoteatr.filmi[menu_number - 1].duration;
	cout << "\n\nРежиссер(-ы): " << kinoteatr.filmi[menu_number - 1].rejisser;
	cout << "\n\nВ главных ролях: " << kinoteatr.filmi[menu_number - 1].main_role;
	cout << "\n\nРасписание сеансов:";
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\n" << uni.date_ret(i) << "   Время   Цена билета";

		for (int j = 0; j < 3; j++)
		{
			
			cout << "\n                " << kinoteatr.filmi[menu_number - 1].time[3 * i + j] << "    " << kinoteatr.filmi[menu_number - 1].price[3 * i + j] << " руб.";
		}
	}


	
}

void Menu::File_choice(int k)
{
	cout << "1) Открыть файл по умолчанию в домашнем каталоге (\"kino_v_teatre\")\n2) Открыть файл по заданному пути";
	if (k == 1)
	{
		cout << "\n3)Создание нового файла\n\nESC - выход";
		item_num = 3;
	}
	else
	{
		cout << "\n\nESC - выход";
		item_num = 2;
	}

}


