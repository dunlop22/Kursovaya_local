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
	cout << "��� ��������� ������ ������� ������� '1'.\n��� ����� � ����� �������������� ������� '2'.\n��� ������ ������� 'esc'.\n\n";
	item_num = 2;
}

void Menu::User_kassir()
{
	system("cls");
	cout << "********name_kinofeatre!!!*******\n\n";
	cout << "1) �������� ������ �������\n2) ���� � ����� ��������������\n\nESC - �����";
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
	cout << "0) ������� � ����\n\n";
	cout << "������ �������:\n\n";
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

	
	
	cout << "\n\n��������: " << kinoteatr.filmi[menu_number - 1].name;
	cout << "\n\n��������: " << kinoteatr.filmi[menu_number - 1].short_description;
	cout << "\n\n�����������������: " << kinoteatr.filmi[menu_number - 1].duration;
	cout << "\n\n��������(-�): " << kinoteatr.filmi[menu_number - 1].rejisser;
	cout << "\n\n� ������� �����: " << kinoteatr.filmi[menu_number - 1].main_role;
	cout << "\n\n���������� �������:";
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\n" << uni.date_ret(i) << "   �����   ���� ������";

		for (int j = 0; j < 3; j++)
		{
			
			cout << "\n                " << kinoteatr.filmi[menu_number - 1].time[3 * i + j] << "    " << kinoteatr.filmi[menu_number - 1].price[3 * i + j] << " ���.";
		}
	}


	
}

void Menu::File_choice(int k)
{
	cout << "1) ������� ���� �� ��������� � �������� �������� (\"kino_v_teatre\")\n2) ������� ���� �� ��������� ����";
	if (k == 1)
	{
		cout << "\n3)�������� ������ �����\n\nESC - �����";
		item_num = 3;
	}
	else
	{
		cout << "\n\nESC - �����";
		item_num = 2;
	}

}


