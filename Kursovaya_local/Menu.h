#pragma once
#include "Kinoteatr.h"
#include "Universal.h"

class Menu
{
public:
	int item_num;
	int menu_number;
	int num_day;	//����� ��� ��� ������� ������
	int num_film;	//����� ���������� ������
	int num_time;
	//char menu_text[512];

public:
	//Menu();
	//Menu(const char* menu_text, int item_num);
	//~Menu();
	//void print();

	//������������
	void User_kassir();
	void Start_menu();
	void Input_number();
	void File_choice(int k);
	void Spisok_kino(Kinoteatr kinoteatr);
	void Opisanie(Kinoteatr kinoteatr);

	//��������������
	int Input_password();
	void Administrator();
	void Edit_cinema();
};

